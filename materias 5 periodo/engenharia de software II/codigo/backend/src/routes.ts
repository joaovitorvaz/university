import { Router } from "express";
import { ensureAuthenticated } from "./middlewares/ensureAuthenticated";
import createGameController from "./controllers/Game/createGameController";
import authenticateUserController from "./controllers/User/authenticateUserController";
import createUserController from "./controllers/User/createUserController";
import listUserController from "./controllers/User/listUserController";
import updateUserController from "./controllers/User/updateUserController";
import createRentController from "./controllers/Rent/createRentController";
import listUsersController from "./controllers/User/listUsersController";
import listGamesController from "./controllers/Game/listGamesController";
import listGameController from "./controllers/Game/listGameController";

const routes = Router();

routes.post("/login", authenticateUserController.handle);

routes.get("/users/listUser", ensureAuthenticated, listUserController.handle);
routes.get("/users/listUsers", listUsersController.handle);
routes.post("/users/createUser", createUserController.handle);
routes.put(
  "/users/updateUser",
  ensureAuthenticated,
  updateUserController.handle
);

routes.post("/games/createGame", createGameController.handle);
routes.get("/games/listGames", listGamesController.handle);
routes.get("/games/listGame", listGameController.handle);

routes.post(
  "/rents/createRent",
  ensureAuthenticated,
  createRentController.handle
);

export default routes;
