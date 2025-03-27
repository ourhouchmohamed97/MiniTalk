import figlet from 'figlet';
import chalk from 'chalk';
console.clear();
figlet.text('MiniTalk', { font: 'Big' }, function (err, data) {
    if (err) {
        console.log('Something went wrong...');
        console.dir(err);
        return;
    }
    const solidColorText = chalk.cyan.bold(data); 
    console.log(solidColorText);
});