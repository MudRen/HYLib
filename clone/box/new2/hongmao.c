// hongmao.c

inherit NPC;

void create()
{
	set_name("��ë��", ({ "hongmao gui", "gui"}));
	set("gender", "����");
	set("age", random(10) + 30);
	set("str", 25);
	set("dex", 16);
	set("long", "�������쳯����̨��ĺ�����ë�������϶���һ֧��ǹ��ǹ�ڻ�ð�����̡�\n");
	set("combat_exp", 250000);
	set("shen_type", 1);
	set("attitude", "peaceful");
set("neili",120000);
set("qi",120000);
set("max_qi",120000);
set("jing",120000);
set("no_get",1);
	set_temp("apply/attack", 130);
	set_temp("apply/defense", 130);
	set_temp("apply/armor", 130);
	set_temp("apply/damage", 130);
      set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
		(: command("use huoqiang") :),
		(: command("use huoqiang") :),
//           (: random_move :),
        }) );
	setup();
	carry_object(__DIR__"obj/huoqiang")->wield();

	carry_object("/clone/box/new2/29");
if (random(10)==0)
	carry_object("/clone/box/new2/30");
if (random(10)==0)
	carry_object("/clone/box/new2/31");
if (random(10)==0)
	carry_object("/clone/box/new2/32");
if (random(10)==0)
	carry_object("/clone/box/new2/33");	
if (random(10)==0)
	carry_object("/clone/box/new2/34");		
if (random(10)==0)
	carry_object("/clone/box/new2/35");			
if (random(10)==0)
	carry_object("/clone/box/new2/36");			
}

void init()
{
	object ob;

	::init();

	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if( environment(ob) != environment() ) return;
	say("��ë��̧�־���һǹ���飡ǹ��һ�Ż��������\n");
	ob->receive_damage("qi",50);
	ob->receive_wound("qi",50);
}

