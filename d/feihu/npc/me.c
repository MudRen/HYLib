//me,hoho
#include <ansi.h>
inherit NPC;
void greeting(object ob);
int accept_object(object who, object ob);
void create()
{
	seteuid(getuid());
        set_name("����Ȼ", ({ "chen xiaoran", "chen", "yafeng" }));
	set("long", "��һ��Ʈ�ݵİ�ɫ������˫�����ƺ��̺��������ǻۡ�\n");
	set("nickname", HIM "��������" NOR);
	set("gender", "����");
	set("age", 22);
	set("attitude", "friendly");
	
	set("str", 25);
	set("int", 24);
	set("con", 25);
	set("dex", 26);

	set("qi", 1000);
	set("max_qi", 1000);
	set("jing", 800);
	set("max_jing", 800);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 10);

	set("combat_exp", 200000);
        set("no_kill",1);
        set("no_fight",1);
        set_temp("no_kill",1);
         set("no_get",1);	
	set_skill("unarmed", 100);
	set_skill("hand", 100);
	set_skill("dodge", 120);
	set_skill("parry", 100);
	set_skill("force", 100);
	set("chat_chance", 10);
	set("chat_msg", ({
		"����Ȼ����: ��������ѩ������һ���ޣ�"+RANK_D->query_respect(this_player())+"��һ���ɡ�\n",
		"ǰ�����һ��"+HIW"�Ʊ���"NOR+"˭�����أ�\n"
		}) );
         setup();
	carry_object("/d/baituo/obj/baipao")->wear();
	
}

void init()
{
	object ob;

	::init();

	if( interactive(ob = this_player()) ) 
       {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}
void greeting(object ob)
{
	
           say(HIY"����ȻЦ��Ц��˵����λ"+RANK_D->query_respect(ob)+
               ",��ӭ������������\n"NOR);
	return;
}

int accept_object(object who, object ob)
{
	object axe;
	if (ob->query("money_id") && ob->value() >= 1000000) 
	{
		tell_object(who, "����Ȼ̾�˿�����˵��������Ǯ�ƣ���....\n");
                axe=new("/d/feihu/obj/snow_axe");
                axe->set_amount(1);
                axe->move(this_player());
                tell_object(who, HIW"\n����Ȼ����һ���Ʊ�����\n"NOR);
		return 1;
	}
       return 0;
}

