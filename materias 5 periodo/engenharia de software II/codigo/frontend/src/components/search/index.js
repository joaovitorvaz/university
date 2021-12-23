import React, {useState} from 'react';
import {SearchSection} from "./styles";
import Input from "../input";

export default function Search({placeholder, size}) {

  const[search, setSearch] = useState("");
  
  return (
    <SearchSection>
        <Input onChange={e => setSearch(e.target.value)} value={search} placeholder={placeholder} size={size}/> 
        {/* TODO <Icon src={SearchIcon} /> */}
    </SearchSection>
  );
}