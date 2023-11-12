let project = new Project("DigDug3000");

project.kore = false

project.addFile("DigDug3000/**");

project.setDebugDir("Deployment");

project.addIncludeDir("ProjetEngin/include");

project.addIncludeDir("DigDug3000/include");

project.flatten();

const otherproj = await project.addProject("ProjetEngin")

otherproj.addProvider(project,true);

resolve(project);