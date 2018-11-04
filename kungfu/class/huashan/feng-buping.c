// feng-buping.c  �ⲻƽ
inherit NPC;
inherit F_MASTER;
#include <ansi.h>

void create()
{
        set_name("�ⲻƽ", ({ "feng buping", "feng" }) );
        set("nickname", YEL"���콣"NOR);
        set("gender", "����");
        set("class", "swordsman");
        set("title", "��ɽ���ڵ�ʮ��������");
        set("age", 45);
        set("long",
                "�ⲻƽ�ǻ�ɽ���ڵ�һ���֣���������һ�Żƽ�������Ƥ��\n");
        set("attitude", "peaceful");
        set("str", 26);
        set("con", 30);
        set("dex", 30);
        set("int", 28);
	set_temp("apply/attack",150);
	set_temp("apply/defense",150);
	set_temp("apply/armor",500);
	set_temp("apply/damage",400);
        set("neili", 12400);
        set("max_neili", 12400);
        set("jiali", 30);
        set("max_qi",12000);
        set("max_jing",11200);

        set("combat_exp", 5000000);
        set("shen", -200000);
        set("apprentice_available", 3);

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
              (: perform_action, "sword.feilong" :),
                (: perform_action, "sword.kuangfeng" :),
                (: perform_action, "sword.kuanglong" :),
                (: perform_action, "sword.sao" :),                
                (: perform_action, "dodge.huiyanfeiwu" :),   
                (: exert_function, "powerup" :),
        }) );
     
        set_skill("zixia-shengong", 320);
        set_skill("unarmed", 200);
        set_skill("strike", 200);
        set_skill("sword", 300);
        set_skill("force", 200);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("literate", 200);
        set_skill("huashan-sword", 250);
        set_skill("kuangfeng-jian", 350);
        set_skill("huashan-neigong", 300);
        set_skill("huashan-ken", 300);
        set_skill("huashan-zhangfa", 300);
        set_skill("huashan-shenfa", 250);
        set_skill("zhengqijue",200);
        map_skill("sword", "kuangfeng-jian");
        map_skill("parry", "kuangfeng-jian");
        map_skill("force", "zixia-shengong");
        map_skill("unarmed", "huashan-zhangfa");
        map_skill("dodge", "huashan-shenfa");

        create_family("��ɽ��", 13, "����");
        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/cloth/cloth")->wear();
}

void attempt_apprentice(object ob)
{
        if( query("apprentice_available") ) {
                if( find_call_out("do_recruit") != -1 )
                        command("say ������һ��һ������");
                else
                        call_out("do_recruit", 2, ob);
        } else {
                command("say �Ϸ�����Ѿ������������ӣ���������ͽ�ˡ�");
        }
}

void do_recruit(object ob)
{
        if( (int)ob->query("int") < 20 )
                command("say �һ�ɽ���Խ���Ϊ�������ҿ�"+RANK_D->query_respect(ob)+"���ʺ���ѧ������");
        else {
                command("say �ã��ã��ã��ܺá�");
                command("recruit " + ob->query("id") );
        }
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
        ob->set("title", "��ɽ���ڵ�ʮ�Ĵ�����");
//                ob->set("class", "huashan");
        add("apprentice_availavble", -1);
}
void reset()
{
//        delete_temp("learned");
        set("apprentice_available", 3);
}

