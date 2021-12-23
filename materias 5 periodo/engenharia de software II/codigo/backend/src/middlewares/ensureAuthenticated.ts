import { NextFunction, Request, Response } from "express";
import { verify } from "jsonwebtoken";
require("dotenv").config();

export function ensureAuthenticated(
  req: Request,
  res: Response,
  next: NextFunction
) {
  const authorization = req.headers.authorization;

  if (!authorization) {
    res.status(401).end();
  }

  const [, token] = authorization.split(" ");

  const { sub } = verify(token, process.env.JWT_TOKEN);

  if (!sub) {
    res.status(401).end();
  }

  req.user_id = sub as string;

  next();
}
