#include <ansi.h>

inherit NPC;

mapping *data=({
(["name":"����",	"id":"xing ren",	"mw":1,	]),
(["name":"����",	"id":"shang ren",	"mw":-1,	]),
(["name":"�ÿ�",	"id":"lv ke",		"mw":1,	]),
(["name":"����",	"id":"men ren",	"mw":1,	]),
(["name":"ѧͽ",	"id":"xue tu",	"mw":1,	]),
(["name":"������",	"id":"wu lai",	"mw":-1,	]),
(["name":"����",	"id":"lang ren",	"mw":-1,	]),
(["name":"����",	"id":"xing she",	"mw":1,	]),
(["name":"����ͽ",	"id":"tu",		"mw":-1,	]),
(["name":"����",	"id":"ke shang",	"mw":-1,	]),
(["name":"С��",	"id":"xiao shi",	"mw":1,	]),
(["name":"��ɫ��",	"id":"se gui",	"mw":-1,	]),
(["name":"����",	"id":"qing nian",	"mw":1,	]),
(["name":"������",	"id":"nian qing",	"mw":1,	]),
});


void create()
{
	mapping npc;
	npc=data[random(sizeof(data))];
	set_name(HIC+npc["name"]+NOR,({ npc["id"] }));
	if( random(10)<5)	set("gender","����");
	else set("gender","Ů��");
	set("age",20+random(30));
	set("combat_exp",5000+random(5000));
	set_temp("apply/attack",20);
	set_temp("apply/defense",20);
	set_temp("apply/armor",20);
	set("max_force",500);
	set_skill("unarmed",30);
	set_skill("parry",30);
	set_skill("dodge",30);
	set("shen_type",npc["mw"]);
	setup();
	carry_object("/clone/cloth/cloth")->wear();
	add_money("silver",5+random(5));
}
       
