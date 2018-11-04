#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void consider();
string ask_me();

void create()
{
    set_name("��ҩʦ", ({"huang yaoshi", "huang", "yaoshi"}));
    set("title", "�һ�����");
    set("nickname", HIY "��а" NOR );
    set("gender", "����");
    set("age", 42);
    set("long", 
        "�������һ����������ºö�ȫ�ɼ��ģ���˱��˳�������а����\n");
    set("attitude", "peaceful");
    set("class", "scholar");
	
    set("str", 21);
    set("int", 30);
    set("con", 26);
    set("dex", 30);

    set("chat_chance", 1);
    set("chat_msg", ({
        "��ҩʦ̾�˿����������� ���� �ض�������ĺ��ӣ���С��û���� ������\n",
        "��ҩʦ��ͷ��˼����Ȼ���\n",
    }));
    set("inquiry", ([
        "����"     : "���ֱ����Ů���Ĺ����� \n",
        "�����澭" : "������ܰ���ȡ���澭�ϲᣬ��һ������л�㡣\n",
    ]));

    set("qi", 15000);
    set("max_qi", 15000);
    set("jing", 13000);
    set("max_jing", 13000);
    set("neili", 13500);
    set("max_neili", 13500);
    set("jiali", 100);

    set("book_count", 1);
    set("combat_exp", 9500000);
    set("score", 0);
	         set_temp("apply/attack", 300);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 550);
    set_skill("leg", 200);             // �����ڹ�
    set_skill("force", 200);             // �����ڹ�
    set_skill("bibo-shengong", 380);     // �̲���
    set_skill("claw", 200);              // ����צ��
    set_skill("hand", 200);              // �����ַ�
    set_skill("finger", 200);            // ����ָ��
    set_skill("tanzhi-shentong", 380);   // ��ָ��ͨ
    set_skill("unarmed", 200);           // ����ȭ��
    set_skill("strike", 200);            // ����ȭ��
    set_skill("luoying-zhang", 380);     // ��Ӣ����
    set_skill("xuanfeng-leg", 380);      // ����ɨҶ��
    set_skill("dodge", 200);             // ��������
    set_skill("anying-fuxiang", 380);    // ��Ӱ����
    set_skill("parry", 200);             // �����м�
    set_skill("sword", 200);             // ��������
    set_skill("luoying-shenjian", 380);  // ��Ӣ��
    set_skill("yuxiao-jian", 380);       // ���｣��
    set_skill("lanhua-shou", 380);       // ������Ѩ��
    set_skill("qimen-wuxing",380);       // ��������
    set_skill("count",150);              // ��������
    set_skill("literate",250);           // ����ʶ��
	
    map_skill("force"  , "bibo-shengong");
    map_skill("finger" , "tanzhi-shentong");
    map_skill("hand"   , "lanhua-shou");
    map_skill("unarmed", "xuanfeng-leg");
    map_skill("leg" , "xuanfeng-leg");
    map_skill("dodge"  , "anying-fuxiang");
    map_skill("parry"  , "yuxiao-jian");
    map_skill("sword"  , "yuxiao-jian");
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 250);
  set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: exert_function, "play" :),
                (: exert_function, "roar" :),
                (: perform_action, "dodge.taohaimangmang" :),
                (: perform_action, "hand.fuxue" :),
                (: perform_action, "sword.taohuajian" :),
                (: perform_action, "sword.taohuajian" :),
                (: perform_action, "sword.tianwai" :),                
                (: perform_action, "sword.yuxiao" :),                
                (: perform_action, "strike.shenjian" :),                
                (: perform_action, "strike.xuan" :),                
                (: perform_action, "leg.kuangfeng" :),                
                (: perform_action, "leg.kuangfeng" :),                
                (: perform_action, "finger.huayu" :),                
                (: perform_action, "finger.jinglei" :),                
                (: perform_action, "finger.lingxi" :),                
        }));
    set("inquiry", ([
        "�ؼ�" : (: ask_me :),
        "����ɨҶ�ȷ�" : (: ask_me :),
    ]));


    create_family("�һ���", 1, "����");
    setup();
	
    carry_object(__DIR__"obj/yuxiao")->wield();
    carry_object(__DIR__"obj/bupao")->wear();
    carry_object("clone/book/jiuyin2");
    
}

void attempt_apprentice(object ob)
{
    if (ob->query_int() < 30) {
        command("say �Ҳ������ʲ�ĵ��ӣ�����ذɣ�");
		return;
    }
    if ((int)ob->query_skill("bibo-shengong",1) < 50 ) {
        command("say ��ı����ڹ��ķ�̫����,����ŬŬ�������һ�°�!");
		return;
    }
    if ((int)ob->query("shen") >100000 || (int)ob->query ("shen") < -100000 ) {
        command("say ���һ��������������������������ֳ�������򽻵�������ذɣ�");
		return;
	}
    command("say �ܺã��ܺá�");
    command("recruit " + ob->query("id"));
}

int recognize_apprentice(object ob)
{
	mapping myfam;
       	myfam = (mapping)ob->query("family");
        if ( myfam["family_name"] == "�һ���") return 1 ;
	if ((int)ob->query_temp("tmark/��") == 1 )
        message_vision("��ҩʦ���˿�$N��˵��������������˭Ҳ��Ƿ˭,\n"
                          "�㲻Ҫ������ѧϰ�����ˡ�\n", ob);
	if (!(int)ob->query_temp("tmark/��"))
		return 0; 
	ob->add_temp("tmark/��", -1);
	return 1;
}

int accept_object(object who, object ob)
{
	
	if ( (string) ob->query("id") =="jiuyin zhenjing1" ) {
 		if (!(int)who->query_temp("tmark/��")) who->set_temp("tmark/��", 0);
		message_vision("��ҩʦ���˿�$N�������ؼ������˵�ͷ��˵����\n"
                               "�ѵ��㽫�澭�ͻء������ҵĶ����Ҿ������ˡ�\n"
                               "��Ϊ����,����Դ�������ѧ�㹦��\n", who);
		who->add_temp("tmark/��", 120);
		return 1;
	}
	return 0;
}
string ask_me()
{
	object ob;
	
	if (this_player()->query("family/master_id")!="huang yaoshi")
		return RANK_D->query_respect(this_player()) + 
		"���ҵ��ӣ���֪�˻��Ӻ�̸��";
	if (query("book_count") < 1)
		return "�������ˣ����ɵ��ؼ����ڴ˴���";
	add("book_count", -1);
	ob = new("/clone/book/xuanfeng_book");
	ob->move(this_player());
	command("rumor "+this_player()->query("name")+"�õ�����ɨҶ�ȷ�����\n");
	return "�ðɣ��Ȿ������ɨҶ�ȷ������û�ȥ�ú����С�";
}
//void die()
//{
//message("channel:rumor", MAG"��ҥ�ԡ�ĳ�ˣ�"+this_player()->query("name")+"���˾����澭�¾�����\n"NOR, users());
//	::die();
//}
