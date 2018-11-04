// hufei.c
#include <ansi.h>;
inherit NPC;
string ask_me();
string ask_book();
void do_kill(object ob);

void create()
{
	set_name("����", ({"di yun", "di", "yun"}));
	set("gender", "����");
	set("nickname", HIR"���ǽ�"NOR);
	set("age", 25);
	set("long", 
		"�����ǵ��Ʒ��Ĵ���ӣ������书��ǿ�����û��\n"
		"�ڽ�����������š����ǽ�����\n"
		"������ȥ����һ�����µ�ũ��\n");
	set("attitude", "peaceful");
	set("str", 45);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("per", 25);
	set("chat_chance", 20);
	set("chat_msg", ({
		"����̾�˿�����������֪ʲôʱ�����ټ���ʦ�á�\n",
		"���ƺ޺޵���������ɽ����ɱʦ���ˣ��ұر��˳𣡡�\n",
		"�����гݺ޵��������������¶��֣��ұ����д��ˣ���\n",
		(: random_move :),
	}));
         set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.ci" :),
                (: perform_action, "sword.erguang" :),
                (: perform_action, "sword.gan" :),
                (: perform_action, "sword.qian" :),
                (: perform_action, "sword.qu" :),
                (: perform_action, "sword.zhai" :),                	                	                	
                (: perform_action, "sword.zhu" :),                	                	                	
		            (: random_move :),
        }) );

	
	set("qi", 13000);
	set("max_qi", 13000);
	set("jing", 11000);
	set("max_jing", 11000);
	set("neili", 23000);
	set("max_neili", 23000);
	set("jiali", 100);
	set("combat_exp", 2990000);
	set("score", 20000);
	 
	set_skill("force", 110);             // �����ڹ�
	set_skill("liancheng-jian", 350);       // ���ҵ���	
	set_skill("sword", 320);             // ��������
	set_skill("hunyuan-yiqi", 320);      // ��Ԫһ����
	set_skill("dodge", 120);             // ��������
	set_skill("shaolin-shenfa", 220);    // ������
	set_skill("parry", 220);             // �����м�
		
	map_skill("force", "hunyuan-yiqi");
	map_skill("sword", "liancheng-jian");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("parry", "hujia-daofa");
        set_temp("apply/attack", 120);
        set_temp("apply/defense", 120);
        set_temp("apply/armor", 120);
        set_temp("apply/damage", 520);

	set("inquiry",([
		"����":     (: ask_book :),
		"����ɽ":     "����ɽ��������ҷ�ɱ�������ɡ�\n",
	]));
	set("baodao_count",1);
	set("book_count",1);
	setup();
	carry_object("clone/weapon/gangjian")->wield();
	carry_object("/d/city/obj/cloth")->wear();
}


void do_kill(object ob)
{
	object me, room1;       
	me = this_object();
//	room1 = environment(me);
 
//	if (room1->query("no_fight"))
//	    room1->set("no_fight", 0);
 
	if (interactive(ob))
	{
		command("say ����������Ҵ��ҽ��׵����⣬������������\n");
		me->set_leader(ob);
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob);
	}
 
}	

int accept_object(object me, object ob)
{
	int i;
	if( !me || environment(me) != environment() ) return 0;
	if ( !objectp(ob) ) return 0; 
	if ( !present(ob, me) ) return notify_fail("��û�����������");
	if ( (string)ob->query("id") == "wan zhenshan") 
	{
		write(HIC "\n����˵������λ" + RANK_D->query_respect(me)+"����˴����£�����ʵ��֪����Ϊ����\n");
		write(HIC "\n���ƴ�ϲ�����������벻����Ҳ�н��죡�������䣬���ֻ���Ϊ���Ρ�\n"NOR);
                call_out("destroying", 1, this_object(), ob);
//		ob->die();
		me->set_temp("marks/lianchenpu",1);
        }
	return 1;
}

string ask_book()
{
	object ob, me;
	
	me = this_player();
	if (!me->query_temp("marks/lianchenpu",1)) return "��˵ʲô? \n";
	if((int)(me->query("shen")<100000))
		return "����������С֮�֣�����������ɽ�ڶ���\n";

   	else 
	{
		if(query("book_count") > 0)
		{		
		write(HIC "����˵��ת�������ɽʬ�����ѳ�һ���ƾ��鱾�����˸��㡣\n");
	    		call_out("waiting",0,me,ob);
			add("book_count", -1);
    			ob = new ("/clone/book/lian_book");
    			ob->move(this_player());
			command("rumor "+me->query("name")+"�õ����ǽ�������\n");
			return "�Ȿ���ǽ��ױ��⹷����ռ��ʱ�ˣ����ھ�������ɡ�\n";
		}
		else return "�������ˣ��������ǽ����Ѳ��ڴ˴���\n";
	}

}

void destroying(object me, object obj)
{
        destruct(obj);
        return;
}
