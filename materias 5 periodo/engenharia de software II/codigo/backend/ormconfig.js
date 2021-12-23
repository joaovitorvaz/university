module.exports = {
  type: "mysql",
  // url: process.env.CLEARDB_DATABASE_URL,
  host: "localhost",
  port: 3306,
  username: "root",
  password: "root",
  database: "ENG2",
  migrations: ["src/database/migrations/*.ts"],
  entities: ["src/entities/*.ts"],
  cli: {
    migrationsDir: "src/database/migrations",
    entitiesDir: "src/entities",
  },
};
