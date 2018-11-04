#include <ansi.h>
int do_walk();
inherit NPC;
string *first_name = ({ "��","Ǯ","��","��","��","��","֣","��","��","��","��","��","��","��", }); 
string *name_words = ({ "һ","��","��","��","��","��","��","��","��","ʮ", });
string *color_title = ({"[��ɱ��]ɱ��","[��ɷ��]ɱ��",});
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});
mapping *data=({
(["name":"�佫",	"id":"wu jiang",	"mw":-1,	]),
(["name":"ɽ��ͷ",	"id":"shan zeitou",	"mw":1,	]),
(["name":"�͵���",	"id":"huo ji",	"mw":-1,	"weapon":"gangdao",	]),
(["name":"����",	"id":"shi wei",	"mw":1,	"weapon":"changqiang",	]),
(["name":"����",	"id":"tie jiang",	"mw":1,	"weapon":"gangdao",	]),
(["name":"��åͷ",	"id":"liumang tou",	"mw":-1,	"weapon":"gangjian",	]),
(["name":"����",	"id":"gui gongzi",		"mw":1,	"weapon":"gangjian",	]),
(["name":"����",	"id":"xing ze",	"mw":1,	"weapon":"gangdao",]),
(["name":"����ͷ",	"id":"tufei tou",	"mw":-1,	"weapon":"changbian",	]),
(["name":"Ϸ��",		"id":"xi zi",	"mw":-1,	"weapon":"lianzi",]),
(["name":"̨���̷�",	"id":"shang fan",		"mw":-1,	"weapon":"hammer",	]),
(["name":"��������",	"id":"yi ren",	"mw":1,	"weapon":"gangjian",]),
(["name":"������",	"id":"kanzu ren",	"mw":-1,	"weapon":"changbian",	]),
(["name":"����",		"id":"lie ren",	"mw":-1,	"weapon":"lianzi",]),
(["name":"̨������",	"id":"old lieren",		"mw":-1,	"weapon":"hammer",	]),
(["name":"������",	"id":"muyang ren",	"mw":1,	"weapon":"gangjian",]),
(["name":"ũ��",	"id":"nong fu",	"mw":1,	"weapon":"gangjian",]),
(["name":"Ƥ����",	"id":"pihuo sang",	"mw":-1,	"weapon":"changbian",	]),
(["name":"ʯ��",		"id":"shi jiang",	"mw":-1,	"weapon":"lianzi",]),
(["name":"����",	"id":"dao ren",		"mw":-1,	"weapon":"hammer",	]),
(["name":"�ο�",	"id":"you ke",	"mw":1,	"weapon":"gangjian",]),
(["name":"��ͯ",	"id":"shu tong",	"mw":1,	"weapon":"gangjian",]),
(["name":"��Ӫ����",	"id":"guan bing",	"mw":-1,	"weapon":"changbian",	]),
(["name":"Ա��",		"id":"yuan wai",	"mw":-1,	"weapon":"lianzi",]),
(["name":"����",	"id":"bi qiu",		"mw":-1,	"weapon":"hammer",	]),
(["name":"��å",	"id":"liu mang",	"mw":1,	"weapon":"gangjian",]),
});


void create()
{
	mapping npc;
	string weapon;
	npc=data[random(sizeof(data))];
	weapon=npc["weapon"];

	set_name(npc["name"],({ npc["id"] }));
	set("age",20+random(30));
	set("combat_exp",20000);
	if( weapon)	set_skill("blade",20);
	set_skill("unarmed",20);
        set("tasknpc",1);
        set("dex",100);
	set_skill("sword",20);
	set_skill("club",20);
	set_skill("whip",20);
	set_skill("throwing",20);
	set_skill("parry",20);
	set_skill("dodge",20);
	set("shen_type",npc["mw"]);
        set("chat_chance", 20);
        set("chat_msg", ({
                (: do_walk :),
                (: random_move :),
        }) );
        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
           (: random_move :),
           (: random_move :),
           (: random_move :),
        }) );

        set_temp("apply/attack", 20);
        set_temp("apply/defense", 20);
        set_temp("apply/armor", 20);
        set_temp("apply/damage", 20+random(80));

        setup();
        set("check_time", time());
	carry_object("/clone/cloth/cloth")->wear();
//	if( weapon)
// 	carry_object("/clone/weapon/"+weapon)->wield();
	add_money("silver",50+random(50));
}
       
int do_walk()
{
        string start_room;
 string name,weapon;
        object room;
        object ob;
        mapping obmap;
        int n;
        int i;
	object *inv;
        if (! environment())
                return 0;
        name = color_title[random(sizeof(color_title))]+first_name[random(sizeof(first_name))];
        name += name_words[random(sizeof(name_words))]; 
//1800
//        if (time() - query("check_time") > 3600)
      if (time() - query("check_time") > 3000 && random(100)>98 || !query_heart_beat(this_object()))
        {
       set_name((order[random(13)])+name, ({ "killer", "shashou", "sha shou" }));
       set("gender", "����");
       set("title", color_title[random(sizeof(color_title))]);
        n = 0;
	inv = all_inventory(this_object());

	for (i = 0; i < sizeof(inv); i++)
        {
                if (inv[i]->query("dynamic_quest"))
command("chat "+inv[i]->query("name")+(order[random(13)])+"���Ѿ��õ����ˡ�������!!  \n"NOR);
        }

                        message_vision("$NЦ��Ц˵�������Ѿ����֣�������ɣ����ˣ�\n"NOR, this_object());
                        destruct(this_object());
                        return 0;
        }

        n = 0;
        foreach (ob in all_inventory(environment()))
        {
                if (!ob->query("dynamic_quest"))
                        continue;
        command ("get all");
                n++;
        }

                        
        random_move();
        return 1;
}

int accept_fight(object ob)
{
				command("say " + RANK_D->query_self(this_object())
					+ "��ô������" + RANK_D->query_respect(ob)
					+ "�Ķ��֣�\n");
		  return 0;
}

int kill_ob(object ob)
{
		  command("fear");
		  command("say ���ã��ұ�ʶ����!!");
//if (random(3)==1)
//{
command("say �Ӱ�!!");
//if (random(2)==1)
//{
command("go south");
command("go west");
//}
//else
//{
command("go north");
command("go east");
//}
//}
if (ob->query("combat_exp") > 1500000)
{
set("qi",2000);
set("jing",2000);
set("eff_qi",2000);
set("eff_jing",2000);
set("max_qi",2000);
set("max_jing",2000);
}
		  return 1;
}


