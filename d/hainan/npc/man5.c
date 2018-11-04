#include <ansi.h>

inherit NPC;

mapping *data=({
(["name":"���̰���",	"id":"bang",		"mw":1,	]),
(["name":"����а��ͽ",	"id":"tu",		"mw":-1,	]),
(["name":"��ػ����",	"id":"bang",		"mw":1,	"weapon":"blade",	]),
(["name":"ؤ�����",	"id":"dizi",		"mw":1,	"weapon":"club",	]),
(["name":"���»����",	"id":"bang",		"mw":1,	"weapon":"blade",	]),
(["name":"���޵���",	"id":"dizi",		"mw":-1,	"weapon":"blade",	]),
(["name":"��ǰ����",	"id":"shiwei",	"mw":1,	"weapon":"sword",	]),
(["name":"�䵱����ͽ",	"id":"dizi",		"mw":-1,	"weapon":"sword",]),
(["name":"��ɽ����ͽ",	"id":"dizi",		"mw":-1,	"weapon":"sword",	]),
(["name":"���չ�ʹ��",	"id":"shizhe",	"mw":-1,	"weapon":"whip",]),
(["name":"���ߵ�ʹ��",	"id":"shizhe",	"mw":-1,	"weapon":"blade",	]),
(["name":"���̽���ʹ",	"id":"shi",		"mw":1,	"weapon":"hammer",]),
});


void create()
{
	mapping npc;
	string weapon;
	npc=data[random(sizeof(data))];
	weapon=npc["weapon"];

	set_name(npc["name"],({ npc["id"] }));
	set("age",20+random(30));
	set("combat_exp",500000+random(500000));
	set_temp("apply/attack",220);
	set_temp("apply/defense",220);
	set_temp("apply/armor",80);
	set("max_force",1500);
	if( weapon)	set_skill(weapon,150);
	set_skill("unarmed",150);
	set_skill("parry",150);
	set_skill("dodge",150);
	set_temp("apply/attack",120);
	set_temp("apply/defense",20);
	set_temp("apply/armor",120);
	set("max_neili",500+random(5550));
	set("max_jing",500+random(5550));
		set("max_qi",500+random(5550));	
        set("chat_chance", 20);
        set("chat_msg", ({
 (: random_move :)

        }) );
		
	set("shen_type",npc["mw"]);
	setup();
	carry_object(__DIR__"weapon/cloth")->wear();
	if( weapon)
		carry_object(__DIR__"weapon/"+weapon)->wield();
	add_money("silver",40+random(40));
}
       
