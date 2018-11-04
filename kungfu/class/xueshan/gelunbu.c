// /kungfu/class/xueshan/gelunbu.c  ���ײ�
// by secret

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
string ask_fashi();
string ask_fashi2();
void create()
{
        set_name("���ײ�", ({ "gelunbu", "ge" }));
        set("long",@LONG
���ײ���ѩɽ���л���ɮ����ͷ�졣ͬʱ���µ��Ӵ����书��
��һ����ɫ���ģ�ͷ��ɮñ��
LONG
        );
        set("title", HIY "����" NOR);
        set("nickname", HIG "ɮ��ͷ��" NOR);
        set("gender", "����");
        set("age", 30);
        set("attitude", "heroism");
        set("shen_type", -1);
        set("str", 200);
        set("int", 20);
        set("con", 28);
        set("dex", 25);

        set("max_qi", 10000);
        set("max_jing", 5000);
        set("neili", 10000);
        set("max_neili", 1000);
        set("jiali", 20);
        set("combat_exp", 800000);
        set("score", 40000);

        set_skill("lamaism", 280);
        set_skill("literate", 130);
        set_skill("force", 180);
        set_skill("xiaowuxiang", 180);
        set_skill("dodge", 175);
        set_skill("shenkong-xing", 170);
        set_skill("parry", 160);
        set_skill("cuff", 100);
        set_skill("staff", 180);
        set_skill("xiangmo-chu", 370 );
        set_skill("unarmed", 160);
        set_skill("yujiamu-quan", 160);
        set_skill("sword", 160);
        set_skill("mingwang-jian", 160);

        map_skill("force", "xiaowuxiang");
        map_skill("dodge", "shenkong-xing");
        map_skill("parry", "xiangmo-chu");
        map_skill("staff", "xiangmo-chu");
        map_skill("sword","mingwang-jian");
        map_skill("unarmed","yujiamu-quan");
	set("inquiry", ([
		"׼������" : (: ask_fashi :),
		"����" : (: ask_fashi :),
		"��ʼ����" : (: ask_fashi2 :),	
	]));

        create_family("ѩɽ��", 5, "����");
        set("class", "bonze");

        setup();

        carry_object("/d/xueshan/obj/b-jiasha")->wear();
        carry_object("/d/xueshan/obj/sengmao")->wear();
        carry_object("/d/xueshan/obj/senggun")->wield();

        add_money("silver",100);
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
	int bonus;
//	if( !ob || environment(ob) != environment() ) return;
//	if( environment(ob)->query("short") == "ѩɽ��̳" )
	if (!(int)ob->query_temp("������")) return;
	{
message_vision("���ײ�����ææ�Ը�С����������̳����񣬵����͡�\n\n", ob);
message_vision(HIR"$N��ȼ�˼�̳�е�ľ�������ͣ������һ�������\n", ob);
message_vision(HIB"һ˿����������̳��ȽȽ���𡣻�����$N�𷨸��٣��ǻ���ȥ��\n", ob);
message_vision(RED"$N����­������һ��ˮ�����ۡ���һ���͵س������ܻ����罫��ȥ��\n", ob);
message_vision(HIC"$N���ȴ�����������̣����������дǣ�������һ˿������$N��ǰ���۳��Ρ�\n", ob);
message_vision(HIG"����Խ��Խ�࣬��Ȼ�ʳ����Σ�$N��ָ���Σ��������ԣ�ָ������֮·��\n", ob);
message_vision(HIW"$N�ֳַ��壬���߱�ҡ�������ж��ܴ����䡣ͻȻ���һ��������������\n", ob);
message_vision(HIY"��Ժ���â����һ����������ָֻ���ƽ����������ϡ�\n"NOR, ob);
		if (ob->query_temp("������") > (int)ob->query("combat_exp"))
		{
			bonus= ob->query_skill("lamaism",1) / 2;
			if ((int)ob->set_temp("��ҷ���"))
{
				ob->add("combat_exp", random(2000) + 300);
				ob->add("potential", random(400) + 200);
                                ob->start_busy(8);
}
	                	else 
{
				ob->add("combat_exp", random(300) + 200);
				ob->add("potential", random(230) + 80);
                                ob->start_busy(8);
}
		}
		else
message_vision(HIR"\n$N��֪���������˸�����ɷ�н��µ������ȣ������ǰ�æ�ˡ�\n"NOR, ob);
				ob->add("jing", -(int)ob->query("jing")/8);
				ob->add("qi", -(int)ob->query("qi")/8);
                                ob->start_busy(8);
                                ob->delete_temp("������");
		command("say �����Ѿ����ꡣ");
	        ob->apply_condition("gelunbu",5+random(8));
if (present("corpse",this_object()))
destruct(present("corpse",this_object()));
if (present("skeleton",this_object()))
destruct(present("skeleton",this_object()));
//		command("drop corpse");
//		command("drop skeleton");
		//command("go north");
		//command("go east");
		//command("go south");
                                	}
}

void attempt_apprentice(object ob)
{

        if ((string)ob->query("gender") != "����") {
                command("say ��ϰ�����ڹ���Ҫ����֮�塣");
                command("say ��λ" + RANK_D->query_respect(ob) +
                        "������ذɣ�");
                return;
        }

        command("say �Ҿʹ���һЩ�书�ɣ�");
        command("recruit " + ob->query("id"));

        if((string)ob->query("class") != "bonze")       {
                ob->set("title","ѩɽ���׼ҵ���");
        }
        else    {
                ob->set("title",HIY"С����"NOR);
        }
}
string ask_fashi()
{
	mapping fam; 
		object where,env,obj;
        string region;
	int sp, dp;
	int i, cost;
	int lvl, diff, busy_time;
	        int b1,b2;
int maxpot;	   
	object ob = this_player();
	object me = this_player();

	if( environment(this_object())->query("short") != "ѩɽ��̳" )
		return "�������������£���û�����᣿";
	if (!(fam = ob->query("family")) || fam["family_name"] != "ѩɽ��")
		return "����������������ë�棬Ҳ������ƨ���£�";
	if ( ob->query_skill("lamaism",1) < 30)
		return "��������ķ�����ú��أ�û�����㿪̳�����¡�";

	if ( ob->query_skill("longxiang",1) < 30 && ob->query_skill("xiaowuxiang",1) < 30)
		return "��ı����ڹ�����ú��أ�û�����㿪̳�����¡�";


         if(ob->query_condition("gelunbu")>0)
         return "��ո���������,��������Ϲ����ʲ��?";
        if (me->is_fighting()) 
        return "���������������!";
                if (me->is_busy())
                return "������������!";

if( !environment(me)->query("no_fight"))
{
if (random(40)==1 && me->query("combat_exp") > 1000000)
{
obj=new("/quest/menpaijob/shenlong/menggu"); 
obj->move(environment(me));
obj->do_copy(me,maxpot,2);
obj->set("title",HIY"Ѳɽ�ٱ�"NOR);
obj->set("usename",me->query("name"));
me->start_busy(1);
message_vision(HIC"��������һ�����׺ݵ�Ѳ�߹ٱ���\n"NOR, obj);
message_vision(RED"$N˵��: �������ɮ����˽�Դ���ʬ�壬�����������������ɮ��\n"NOR, obj);
me->kill_ob(obj);
obj->kill_ob(me);
return "�Ȱ����ٱ�������˵�ɣ�";
}
}

	ob->set_temp("����",1);
	return "��λ������Ҫ����λʩ��������ѽ��";
}

int accept_object(object who, object ob)
{
	object myenv ;
	if (!(int)who->query_temp("����"))
	{
		message_vision("���ײ�Ц�Ŷ�$N˵�����ֳ�����������ʲô�ã��������Լ����Űɣ�\n", who);
		return 0 ;
	}
	who->delete_temp("����");
	if (ob->query("id") == "corpse")
	{
		message_vision("���ײ�Ц�Ŷ�$N˵��������ȥ��̳�ɣ�\n", who);
		who->set_temp("������", ob->query("combat_exp"));
		if ((int)ob->query("userp"))
			who->set_temp("��ҷ���", 1);
//	who->set_leader(this_object());
//                destruct(ob);
		//command("go north");
		//command("go west");
		//command("go south");
 
		return 1;
	}
	else  
		message_vision("���ײ���$N˵�����ֶ������������£�ֱ������ʡ�¡�\n", who);
	return 0;
}
string ask_fashi2()
{
	int bonus;
//	if( !ob || environment(ob) != environment() ) return;
//	if( environment(ob)->query("short") == "ѩɽ��̳" )
object ob = this_player();
if (!ob->query_temp("������")) 
{
	command("say ��λ������Ҫ����λʩ��������ѽ��");
return "û��ʬ����ʲô���°���";
}
	if (!(int)ob->query_temp("������")) return "��λ������Ҫ����λʩ��������ѽ��";
	{
message_vision("���ײ�����ææ�Ը�С����������̳����񣬵����͡�\n\n", ob);
message_vision(HIR"$N��ȼ�˼�̳�е�ľ�������ͣ������һ�������\n", ob);
message_vision(HIB"һ˿����������̳��ȽȽ���𡣻�����$N�𷨸��٣��ǻ���ȥ��\n", ob);
message_vision(RED"$N����­������һ��ˮ�����ۡ���һ���͵س������ܻ����罫��ȥ��\n", ob);
message_vision(HIC"$N���ȴ�����������̣����������дǣ�������һ˿������$N��ǰ���۳��Ρ�\n", ob);
message_vision(HIG"����Խ��Խ�࣬��Ȼ�ʳ����Σ�$N��ָ���Σ��������ԣ�ָ������֮·��\n", ob);
message_vision(HIW"$N�ֳַ��壬���߱�ҡ�������ж��ܴ����䡣ͻȻ���һ��������������\n", ob);
message_vision(HIY"��Ժ���â����һ����������ָֻ���ƽ����������ϡ�\n"NOR, ob);
		if (ob->query_temp("������") > (int)ob->query("combat_exp"))
		{
			bonus= ob->query_skill("lamaism",1) / 2;
			if ((int)ob->set_temp("��ҷ���"))
{
				ob->add("combat_exp", random(2000) + 300);
				ob->add("potential", random(400) + 200);
                                ob->start_busy(8);
}
	                	else 
{
				ob->add("combat_exp", random(300) + 200);
				ob->add("potential", random(230) + 80);
                                ob->start_busy(8);
}
		}
		else
message_vision(HIR"\n$N��֪���������˸�����ɷ�н��µ������ȣ������ǰ�æ�ˡ�\n"NOR, ob);
				ob->add("jing", -(int)ob->query("jing")/8);
				ob->add("qi", -(int)ob->query("qi")/8);
                                ob->start_busy(8);
                                ob->delete_temp("������");
		command("say �����Ѿ����ꡣ");
	        ob->apply_condition("gelunbu",5+random(8));
if (present("corpse",this_object()))
destruct(present("corpse",this_object()));
if (present("skeleton",this_object()))
destruct(present("skeleton",this_object()));
}



}