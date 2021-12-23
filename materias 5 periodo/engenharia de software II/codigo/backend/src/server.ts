import "reflect-metadata";
import express, { NextFunction, Request, Response } from "express";
import "express-async-errors";
import routes from "./routes";
import cors from "cors";

import "./database/connection";
import { catchError } from "./middlewares/catchError";
import dotenv from "dotenv";

const app = express();

dotenv.config();
app.use(cors());
app.use(express.json());

app.use(routes);

app.use(catchError);

const PORT = process.env.PORT || 8080;
app.listen(PORT, () => {
  console.log(`App listening on port ${PORT}`);
});
