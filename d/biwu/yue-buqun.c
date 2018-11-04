// yue-buqun.c lasted updated by cocacola on 2.19 for adding chushi
// ����Ⱥ
// ��npc�ϵ�xunshan���ò�����
// ����lywin����2000/6/11

inherit NPC;
inherit F_MASTER;
#include <ansi.h>;
int do_xunshan();

void create()
{
        set_name("����Ⱥ", ({ "yue buqun", "yue" }) );
        set("title", "��ɽ������");
        set("nickname", "���ӽ�");
        set("gender", "����");
        set("class", "swordsman");
        set("age", 55);
        set("long",
                "����Ⱥ����ִ�ƻ�ɽ�ɣ��˵���������һ��һ�ĸ��֡�\n");
        set("attitude", "peaceful");
        set("str", 26);
        set("con", 30);
        set("dex", 30);
        set("int", 28);

        set("neili", 14400);
        set("max_neili", 14400);
        set("jiali", 30);
        set("max_qi",12200);
        set("max_jing",12200);

        set("combat_exp", 12000000);
        set("shen", -200000);
        set_temp("xunshan", 1);
        set("apprentice_available", 3);

        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.jianzhang" :),
                (: perform_action, "sword.jianzhang" :),
                (: perform_action, "sword.feilong" :),                
                (: perform_action, "dodge.huiyanfeiwu" :),                
                (: exert_function, "powerup" :),
        }) );
        set("inquiry", ([
            "Ѳɽ": (: do_xunshan :),
            "job" : (: do_xunshan :),
        ]) );

        set_skill("unarmed", 80);
        set_skill("sword", 200);
        set_skill("force", 200);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("literate", 200);
        set_skill("huashan-sword", 380);
        set_skill("zixia-shengong", 380);
        set_skill("huashan-ken", 380);
        set_skill("feiyan-huixiang", 380);
        set_skill("pixie-sword",380);
        set_skill("zhengqijue",380);

        map_skill("sword", "huashan-sword");
        map_skill("parry", "huashan-sword");
        map_skill("force", "zixia-shengong");
        map_skill("unarmed", "huashan-ken");
        map_skill("dodge", "feiyan-huixiang");
        set_temp("apply/attack", 400);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 350);
        create_family("��ɽ��", 13, "����");
        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/cloth/cloth")->wear();
        carry_object("/clone/book/zixia_book");
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
        add("apprentice_availavble", -1);
}
void reset()
{
        set_temp("xunshan",1);
        set("apprentice_available", 3);
}
int do_xunshan()
{
        object me = this_player();
        if ( me->query_temp("xunshan"))
        {
               if (!me->query_temp("xunshan/chaoyang"))
               {
                      message_vision("$N����$n˵���㳯����ûȥ����������Ѳ��ʲôɽ��\n", this_object(), me);
                      return 1;
               }
               if (!me->query_temp("xunshan/lianhua"))
               {
                      message_vision("$N����$n˵����������ûȥ����������Ѳ��ʲôɽ��\n", this_object(), me);
                      return 1;
               }
               if (!me->query_temp("xunshan/yuntai"))
               {
                      message_vision("$N����$n˵������̨��ûȥ����������Ѳ��ʲôɽ��\n", this_object(), me);
                      return 1;
               }
               if (!me->query_temp("xunshan/sheshen"))
               {
                      message_vision("$N����$n˵������ôûȥ�����£�����Ѳ��ʲôɽ��\n", this_object(), me);
                      return 1;
               }
               if (!me->query_temp("xunshan/siguo"))
               {
                      message_vision("$N����$n˵���㵽��˼����ȥ�ˣ�����Ѳ��ʲôɽ��\n", this_object(), me);
                      return 1;
               }
               if (!me->query_temp("xunshan/yunu"))
               {
                      message_vision("$N����$n˵���㵽��Ů����滪ɽС��ȥ�����ˣ�����Ѳ��ʲôɽ��\n", this_object(), me);
                      return 1;
               }
               message_vision("$N����$n˵�����������ˡ������ȥ��Ϣȥ�ɡ�\n", this_object(), me);
               me->delete_temp("xunshan");                      
               me->add("combat_exp", random(100));
               me->add("potential", random(40));
               return 1;
        }
        else
        {
               if ( query_temp("xunshan") < 1)
               {
                      message_vision("$N����$n˵�������Ѿ�����Ѳɽȥ�ˡ������������ɡ�\n", this_object(), me);
                      return 1;
               }
               if( me->query("family/family_name") != "��ɽ��")
               {
                      message_vision("$N����$n���һ�������ɵ��Ӳ���Ѳɽ�����������ļ�ϸ���ݹ��ҽ��²����飡\n", this_object(), me);
                      this_object()->kill_ob(me);
                      return 1;
               }
               else
               {
                      add_temp("xunshan", -1);
                      message_vision("$N����$n˵�����ɵ�������Ѳɽ���㣬�ܺã��ܺã����ȥ�ɡ�\n", this_object(), me);
                      me->set_temp("xunshan/start", 1);
                      me->set_temp("xunshan/time", time());
                      return 1;
               }
        }
}
