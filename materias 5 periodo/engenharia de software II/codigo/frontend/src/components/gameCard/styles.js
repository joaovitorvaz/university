import styled from 'styled-components';
import {Link} from 'react-router-dom'

export const Card = styled(Link)`
  width: 90%;
  height: 400px;
  cursor: pointer;
  border: none;
  margin: 10px;
  display: flex;
  flex-direction: column;
  justify: center;
  padding: 0px;
  margin-bottom: 50px;
`;

export const Image = styled.img`
  width: 100%;
  height: 80%;
  size: cover;
  repeat: no-repeat, repeat;
`;

export const Info = styled.div`
  width: 100%;
  height: 20%;
  display: flex;
  flex-direction: row;
  justify-content: space-around;
  background-color: ${({ theme }) => theme.colors.gameCard};
`;

export const Data = styled.div`
  width: 50%;
  display: flex;
  flex-direction: column;
  justify-content: center;
  align-items: flex-start;
  padding-left: 20px;
`;

export const DataText = styled.h2`
  font-weight: normal;
  font-size: 1.2rem;
  margin: 0px;
  color: ${({ theme }) => theme.colors.light};
`;

export const Tag = styled.div`
  width: 50%;
  display: flex;
  justify-content: center;
  align-self: center;
  background-color: white;
  margin: 20px;
  border-radius: 10px;
  background-color: ${({ theme }) => theme.colors.light};  
`;

export const TagText = styled.h2`
  font-weight: normal;
  font-size: 1.0rem;
  color: ${({ theme }) => theme.colors.gameCard};
`;