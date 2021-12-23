import { NextFunction, Request, Response } from "express";

export function catchError(
  err: any,
  req: Request,
  res: Response,
  next: NextFunction
) {
  if (err instanceof Error) {
    return res.status(400).json({ err: err.message });
  }

  return res.status(500).json({ type: "Error", message: "Internal Error" });
}
