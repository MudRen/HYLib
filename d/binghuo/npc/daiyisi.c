// daiyisi.c
// Last Modified by winder on Oct. 30 2001

#include "ansi.h";
inherit NPC;
inherit F_MASTER;
inherit F_UNIQUE;
string ask_fan();
int ask_yy();
int ask_mj();

void create()
{
	set_name("���˿", ({"dai yisi", "dai", "yisi", }));
	set("long",
"���˿վ�ڴ�ǰ�����󺣣����������ȴ����ͷ��ֻ������Ӱ��
��㷢Ʈ������շ��������ٹ����ˣ��������ԡ�лѷ˵��
�����������е�һ���ˣ����Ե��治�飬ң��������ϣ���ˮ̶
�ߣ������绨������ʤѩ����֪�㵹�˶���Ӣ�ۺ��ܡ�\n");

	set("nickname", HIM "��������" NOR);
	set("gender", "Ů��");
	set("attitude", "peaceful");

	set("age", 33);
	set("shen_type", 1);
	set("fan",2);
	set("per", 29);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("max_qi", 23500);
	set("max_jing", 21500);
	set("neili", 23000);
	set("max_neili", 23000);
	set("jiali", 150);

	set("combat_exp", 1900000);
	set("score", 800000);

	set_skill("force", 160);
	set_skill("dodge", 140);
	set_skill("throwing", 250);
	set_skill("parry", 140);
	set_skill("sword", 140);
	set_skill("cuff", 140);
	set_skill("hand", 140);
	set_skill("jiuyang-shengong", 360);
	set_skill("qingfu-shenfa", 340);
	set_skill("changquan", 340);
	set_skill("liehuo-jian", 340);
	set_skill("duoming-jinhua", 350);
	set_skill("literate", 300);

	map_skill("force", "jiuyang-shengong");
	map_skill("cuff", "changquan");
	map_skill("hand", "sanshou");
	map_skill("dodge", "qingfu-shenfa");
	map_skill("throwing", "duoming-jinhua");
	map_skill("parry", "changquan");
	map_skill("sword", "liehuo-jian");
	prepare_skill("cuff", "changquan");
	prepare_skill("hand", "sanshou");

        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "throwing.lianhuan" :),
        }) );
	set("inquiry", ([
		"лѷ"   : (: ask_fan :),
		"������" : (: ask_fan :),
		"����" : (: ask_fan :),
              "����" : (: ask_mj :),
             "��Ҷ����" : (: ask_yy :),
             "������" : "�����õ���������ȥ�������������!\n",
	]) );
	set("chat_chance_combat", 200);
	set("chat_msg_combat", ({
		(: command("perform duo") :),
	}) );
	set("party/party_name",HIG"����"NOR);
	set("party/rank",HIW"���̷���"NOR);
	create_family("����", 34, "����");
	setup();
	carry_object("/d/mingjiao/obj/baipao")->wear();
}

void init()
{
	object me,ob;
	me = this_object () ;
	ob = this_player () ;

	::init();

	if (interactive(this_player()) && this_player()->query_temp("fighting"))
	{
		this_player()->start_busy(2);
		COMBAT_D->do_attack(this_object(), this_player(), query_temp("weapon") );
		COMBAT_D->do_attack(this_object(), this_player(), query_temp("weapon") );
		COMBAT_D->do_attack(this_object(), this_player(), query_temp("weapon") );
		this_player()->add_temp("beat_count", 1);
	}
	if( interactive(ob) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, me, ob);
	}
}

string ask_fan()
{
	mapping fam;
	object *allob,env,ob,me=this_player();
	string *sname;
	int i, count, here = 0;

 if (query("fan")<=0)
 return "�����Ѿ������ˡ�";

	add("fan",-1);
	ob = new("/d/binghuo/obj/fan");
	ob->move(me);
	message_vision("$N���һ�淫����\n",me);

	return "�ðɣ����ϼ��գ�����һ�鷫�������Լ�ȥ��л����ɡ�";

}



int ask_mj()
{
        message_vision("���˿������߽һ���:���ǹ�ȥ������,����������!
ͻȻ�ع�ͷ��������$N��:�㾿����˭,��������ʲô��?\n",this_player());
        return 1;
}

int ask_yy()
{
       message_vision("���˿��Ȼ��:��,�����ú�ԩ��!���Ǻ���ţ�⹷������,�Ҳ���Ź�����,
������Ȼ��:���̣����̣�ԭ����������Ϊ������!\n",this_player());
       return 1;
}
#include "fawang.h"
