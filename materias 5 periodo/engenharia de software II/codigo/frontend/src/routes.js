import React, { useState } from 'react';

import { Route, Routes, BrowserRouter as Router} from "react-router-dom";

import NavBar from './components/navbar';

import Home from "./pages/home";
import SignIn from "./pages/signIn";
import SignUp from "./pages/signUp";
import Game from "./pages/game";
import MyGames from "./pages/myGames";
import Historic from "./pages/historic";
import Profile from "./pages/profile";
import Support from "./pages/support";

export default function RoutesNavigation() {
  const [open, setOpen] = useState(false);

  return(
      <Router>
          <NavBar open={open} setOpen={setOpen} />
          <Routes>
            <Route element = { <Home/> } path="/" exact />
            <Route element = { <SignIn/> } path="/signIn" exact />
            <Route element = { <SignUp/> } path="/signUp" exact />
            <Route element = { <Game/> } path="/gamerent" exact />
            <Route element = { <MyGames/> } path="/my-games" exact />
            <Route element = { <Historic/> } path="/historic" exact />
            <Route element = { <Profile/> } path="/profile" exact />
    	      <Route element = { <Support/> } path="/support" exact />
          </Routes>
      </Router>
  )
}