// cool980310
// ������
// cool980724
// Modify By River 98/12
//COOL@SJ 991017
inherit NPC;

string ask_duan1();
string ask_duan2();
int checking(object me);
int do_kill(object me, object ob);
void create()
{
        set_name("���ۿ�", ({ "qingpao ke", "ke"}) );
        set("gender", "����" );
        set("age", 52);
        set("str", 26);
        set("con", 23);
        set("dex", 5);
        set("int", 25);
        set("per", 10);
   	set("attitude", "friendly");

        set("max_qi", 3500);
        set("max_jing", 3000);
        set("eff_jingli", 3000);
        set("neili", 4000);
	set("qi", 3500);	
        set("max_neili", 4000);
        set("jiali", 100);
        
        set("long","�����Ǹ����ߣ����봹�أ���Ŀ��ڡ�\n",);
        set("combat_exp", 1500000);
        set("shen", -20000);

        set("chat_chance_combat", 30);
        set("chat_msg_combat",({ 
           (: perform_action, "finger.sandie" :), 
        }));

        set_skill("parry", 180);
        set_skill("dodge", 160);
        set_skill("force", 180);
        set_skill("finger", 160);
        set_skill("buddhism", 100);
        set_skill("literate", 120);
        set_skill("sword", 130);
        set_skill("duanjia-sword", 120);
        set_skill("kurong-changong", 140);
        set_skill("yiyang-zhi", 160);
        set_skill("xiaoyaoyou", 50);
        map_skill("dodge", "xiaoyaoyou");
        map_skill("parry", "yiyang-zhi");
        map_skill("finger", "yiyang-zhi");
        map_skill("force", "kurong-changong");
        prepare_skill("finger","yiyang-zhi");
        set("inquiry", ([
            "����" : (: ask_duan2 :),
            "name" : (: ask_duan1 :),
            "������" : (: ask_duan1 :),
        ]));

        setup();
        carry_object(__DIR__"obj/pao")->wear();
}

string ask_duan1()
{
        object me,ob;
        ob=this_player();
        me=this_object();
        me->set_name("������", ({ "duan yanqing", "duan","yanqing"}) );
	me->set("title","�Ĵ����");
        me->set("nickname","�����ӯ");
	ob->set_temp("duanyu/ask1",1);
        return ("�Ϸ�����Ĵ�����е��ϴ󣺶�����!\n");
}

string ask_duan2()
{
        object me,ob;
        ob=this_player();
        me=this_object();
		if( ob->query_temp("duanyu/find2")&& ob->query_temp("duanyu/ask1"))
		   {
		   	command("hehe " + ob->query("id"));
	    	call_out("do_kill", 0, me, ob);  

           return ("��ȶ�������������!\n");
		   } else return ("���������ʲô��\n");
		

}

int do_kill(object me, object ob)
{
	me->kill_ob(ob);
	ob->fight_ob(me);
	call_out("checking", 0, me); 	
 	return 1;
}

int checking(object me)
{
       object ob;
       ob=this_player();
       if (!ob->query_temp("kill")) {
       if (me->query("qi")< 100 
        || me->query("eff_qi")<100){
	 ob->set_temp("kill",1);
	 message_vision("$n����$N���һ��������һƬ�����֡�\n", me, ob);
	 message_vision("$n�����ȵ��������ܣ�$n����׷�˹�ȥ��\n", me, ob);
	 ob->move("/d/dali/wuliang/shanlin-1");
	 destruct(me);
         }
       else {   
	 call_out("checking", 1, me);
         return 1;
	 }
    }
}
void die()
{
	message_vision("$N��Ц������ɱ���ң��Ⱳ�ӱ����ҵ������ˡ�\n", this_object());
	destruct(this_object());
}