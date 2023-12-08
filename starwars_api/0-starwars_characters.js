#!/usr/bin/node
const request = require("request");

function getMovieCharacters(movieId) {
  request(
    `https://swapi.dev/api/films/${movieId}/`,
    { json: true },
    (err, res, body) => {
      if (err) {
        return console.log(err);
      }
      if (res.statusCode !== 200) {
        return console.log(`Failed to get data for movie ID ${movieId}`);
      }

      let characters = body.characters;
      characters.forEach((characterUrl) => {
        request(characterUrl, { json: true }, (err, res, body) => {
          if (err) {
            return console.log(err);
          }
          console.log(body.name);
        });
      });
    }
  );
}

const movieId = process.argv[2];

if (!movieId) {
  console.log("Usage: node 0-starwars_characters.js <Movie ID>");
  process.exit(1);
}

getMovieCharacters(movieId);
