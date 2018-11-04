// zhang.c ������
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string ask_me_1();
string ask_me_2();
void create()
{
	set_name("������", ({ "zhang sanfeng", "zhang" }));
	set("nickname", "��������");
	set("long", 
		"�������䵱�ɿ�ɽ���桢�������ֵ�̩ɽ�������������ˡ�\n"
		"��һ���ۻ�Ļ�ɫ���ۣ����ޱ߷���\n"
		"��ĸߴ��������꣬������⣬��ü�԰ס�\n");
	set("gender", "����");
	set("age", 100);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 50);
	set("int", 50);
	set("con", 50);
	set("dex", 50);
	set("qi", 28000);
	set("max_qi", 28000);
	set("jing", 28000);
	set("max_jing", 28000);
	set("neili", 55000);
	set("max_neili", 55000);
	set("jiali", 100);
	set("combat_exp", 9000000);
	set("score", 600000);
	set("shen", 200000);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.zong" :),
                (: perform_action, "unarmed.zhenup" :),
                (: perform_action, "unarmed.tu" :),
                (: perform_action, "unarmed.zhan" :),
                (: perform_action, "unarmed.ji" :),
                (: perform_action, "unarmed.jielidali" :),
                (: perform_action, "hand.leiting" :),
                (: perform_action, "hand.mian" :),
                (: perform_action, "strike.zheng" :),	
                (: perform_action, "sword.lian" :),
                (: perform_action, "sword.chan" :),
                (: perform_action, "sword.chanup" :),
                (: perform_action, "sword.sui" :),
                (: perform_action, "sword.lian" :),
                (: perform_action, "sword.zhenwu" :),
                (: perform_action, "sword.lian" :),                
        }) );
set_skill("claw", 250);
set_skill("strike", 380);
	set_skill("force", 550);
	set_skill("taiji-shengong", 380);
	set_skill("dodge", 150);
	set_skill("tiyunzong", 380);
	set_skill("unarmed", 200);
	set_skill("taiji-quan", 380);
	set_skill("parry", 300);
	set_skill("sword", 300);
	set_skill("taiji-jian", 380);
	set_skill("liangyi-jian", 150);
	set_skill("wudang-array", 380);
	set_skill("array",100);
	set_skill("taoism", 500);
	set_skill("literate", 200);
	set_skill("yitian-tulong", 380);
	set_skill("juehu-shou", 380);
	set_skill("raozhi-roujian", 380);
	set_skill("wudang-mianzhang", 380);
	set_skill("hand", 280);
	set_skill("paiyun-shou", 380);
	set_skill("shenmen-jian", 380);
	set_skill("yitian-zhang", 280);
	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "taiji-quan");
	map_skill("sword", "taiji-jian");
		map_skill("hand", "paiyun-shou");
			map_skill("strike", "yitian-zhang");
//prepare_skill("hand", "paiyun-shou");
//prepare_skill("strike", "yitian-zhang");
set("count",1);
	set_temp("apply/attack",150);
	set_temp("apply/defense",150);
	set_temp("apply/armor",500);
	set_temp("apply/damage",400);
        set("inquiry", ([
                "���佣" : (: ask_me_1 :),
                  "����" : (: ask_me_2 :),
        ]));
	create_family("�䵱��", 1, "��ɽ��ʦ");
	set("class", "taoist");

	setup();
	carry_object("/clone/weapon/changjian")->wield();
}

void attempt_apprentice(object ob)
{
        if ((int)ob->query("guarded") < 5) {
                command("say " + RANK_D->query_respect(ob) +
                        "������䵱�ɾ��˶����������м��������أ�");
                return;
        }
	if ((int)ob->query_skill("taiji-shengong", 1) < 60) {
		command("say ���䵱�����ڼ��书���������ڹ��ķ���"); 
		command("say " + RANK_D->query_respect(ob) + 
			"�Ƿ�Ӧ����̫�����϶��µ㹦��");
		return;
	}
    if ((int)ob->query_skill("taoism", 1) < 80)
    {
        command("say ���䵱���˵����书��������书�벻����ѧ�ķ���");
        command("say " + RANK_D->query_respect(ob) +
            "�Ƿ�Ӧ�ö�������¾���");
        return;
    }
	if ((int)ob->query("shen") < 2000) {
		command("say ѧ��֮�ˣ�����Ϊ�ȣ�����ĸߵ͵�������Σ�δ���䣬Ҫ��ѧ���ˡ�");
		command("say �ڵ��з��棬" + RANK_D->query_respect(ob) +
			"�Ƿ����ò�����");
		return;
	}
	if (ob->query_int() < 30) {
		command("say ���䵱���书ȫ�ӵ��������");
		command("say Ҫ�ܴﵽ¯����֮��������ʲô�ĵ����޹ؽ�Ҫ������ȴ�ǰ��Ҳ�����á�");
		command("say " + RANK_D->query_respect(ob) + "�����Ի�����Ǳ�����ڣ�������ذɡ�");
		return;
	}
	command("chat ����������������");
	command("chat �벻���ϵ��ڴ���֮�꣬���ٵ�һ������֮�ţ����ǿ�ϲ�ɺء�");
	command("recruit " + ob->query("id"));
}

string ask_me_1()
{
        mapping fam; 
        
        if (!(fam = this_player()->query("family")) || fam["family_name"] !="�䵱��")
                return RANK_D->query_respect(this_player())+"�뱾��������������֪�˻��Ӻ�̸��";

        if (!this_object()->query("count"))
		return "���������Ϻ�Ϳ�ˣ�����֪�����ˡ�\n";

        command("pat "+ (string)this_player()->query("id"));
        return "�˽��˱�����ɽ֮��������������������ܷ��Ľ��㱣�ܣ�\n";
}

string ask_me_2()
{
        mapping fam; 
        
        if (!(fam = this_player()->query("family")) || fam["family_name"] !="�䵱��")
                return RANK_D->query_respect(this_player())+"�뱾��������������֪�˻��Ӻ�̸��";
        command("thumb "+ (string)this_player()->query("id"));
           return "��ѹ�Ů�����ҵ�����������������ͨ�����飡�㵽������ʱ�����ĸ����Ұɡ�\n";
}

int accept_object(object who, object ob)
{
        object sword, me;
        mapping fam;
        me = this_object();

        if (!(fam = this_player()->query("family")) || fam["family_name"] !="�䵱��")
           {
             command("thank "+ (string)who->query("id"));
             command("say ���뱾��������������֪Ϊ������˺��� \n");
//        call_out("destroying", 1, ob);
             return 0;
            }
        
    if (fam["generation"] == 2)
        if ((string)ob->query("id") == "tie luohan")
        {
            command("goodkid "+(string)who->query("id"));
            call_out("destroying", 1, ob);
	    if (present("zhenwu jian", who)) {
                command("? " + who->query("id"));
                command("say �����Ѿ���������");
		return 1;
	    }
            if (!me->query("count")) {
                command("say �������Ϻ�Ϳ�ˣ�����֪�����ˡ�\n");
                return 1;
            }
            sword = new("/clone/unique/zhenwu-jian");
            sword->move(this_player());
	    me->set("count", 0);
            command("say ��������⽣Ϊ���������ұ�ȡ������!\n");
            return 1;
        }
        command("? "+ (string)who->query("id"));
        command("say ���첻���ϵ������գ�����ʲô��ѽ��");

//    call_out("destroying", 1, ob);
    return 0;
}

void destroying(object obj)
{     
    if (!obj) return;
    if (userp(obj)) command("drop "+obj->parse_command_id_list()[0]);
    else destruct(obj);
}
