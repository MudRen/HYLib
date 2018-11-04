// yue-buqun.c lasted updated by cocacola on 2.19 for adding chushi
// ����Ⱥ
// ��npc�ϵ�xunchen���ò�����
// ����lywin����2000/6/11
//  hxsd���ֶ��xunchen����BUG����һ�ַ�����
inherit NPC;
#include <ansi.h>;
int do_xunchen();

void create()
{
        set_name("������", ({ "wang daren", "wang" }) );
        set("title", "ƽ�����ؽ�");
        set("nickname", "�޵н���");
        set("gender", "����");
        set("class", "swordsman");
        set("age", 55);
        set("long",
                "����������ƽ���ǵ��سǴ󽫡�\n");
        set("attitude", "peaceful");
        set("str", 26);
        set("con", 30);
        set("dex", 30);
        set("int", 28);

        set("neili", 2400);
        set("max_neili", 2400);
        set("jiali", 30);
        set("max_qi",2000);
        set("max_jing",1200);

        set("combat_exp", 1000000);
        set("shen", 2000);
        set_temp("xunchen", 80);
        set("apprentice_available", 3);

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: exert_function, "powerup" :),
        }) );
        set("inquiry", ([
            "Ѳ��": (: do_xunchen :),
            "job" : (: do_xunchen :),
        ]) );

        set_skill("unarmed", 80);
        set_skill("sword", 100);
        set_skill("force", 100);
        set_skill("parry", 100);
        set_skill("dodge", 100);
        set_skill("literate", 100);
        set_skill("huashan-sword", 100);
        set_skill("zixia-shengong", 100);
        set_skill("huashan-ken", 80);
        set_skill("feiyan-huixiang", 100);
        set_skill("pixie-sword",80);
        set_skill("zhengqijue",100);

        map_skill("sword", "huashan-sword");
        map_skill("parry", "huashan-sword");
        map_skill("force", "zixia-shengong");
        map_skill("unarmed", "huashan-ken");
        map_skill("dodge", "feiyan-huixiang");

        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/cloth/cloth")->wear();
}

void reset()
{
        set_temp("xunchen",1);
}
int do_xunchen()
{
        object *ob_list;
        int i;
        object me = this_player();
        if ( me->query_temp("xunchen"))
        {
        if (present("xunchen1", me)  && present("xunchen2", me)&& present("xunchen3", me)&& present("xunchen4", me))  
         {
               message_vision("$N����$n˵�����������ˡ������ȥ��Ϣȥ�ɡ���ľ����Ǳ��������!!\n", this_object(), me);
               me->delete_temp("xunchen");                      
                 destruct(present("xunchen1",me));
                 destruct(present("xunchen2",me));
                 destruct(present("xunchen3",me));
                 destruct(present("xunchen4",me));
               me->add("combat_exp", random(300));
               me->add("potential", random(100));
               return 1;
         }
        else
        command("say ���Ѳ�Ǳ��棬��ûȫ��!");
        return 1;
        }
        else
        {
               if ( query_temp("xunchen") < 1)
               {
                      message_vision("$N����$n˵�������Ѿ��в�����Ѳ��ȥ�ˡ������������ɡ�\n", this_object(), me);
                      return 1;
               }
               if( me->query("combat_exp") <30000)
               {
                      message_vision("$N����$n��Цһ��������������Ҳ��Ѳ�ǣ�\n", this_object(), me);
                      return 1;
               }
               if( me->query("combat_exp") >300000)
               {
                      message_vision("$N����$n˵������ô��С�£�����������ݣ�\n", this_object(), me);
                      return 1;
               }
               else
               {
                      add_temp("xunchen", -1);
                      message_vision("$N����$n˵�����ж�����Ѳ�ǡ��㣬�ܺã��ܺã����ȥ�ɡ�\n", this_object(), me);
//                      me->set_temp("xunchen/start", 1);
//                      me->set_temp("xunchen/time", time());
                      me->set_temp("xunchen", 1);
                        ob_list = children("/d/pingan/feizi/feizei");
              for(i=0; i<sizeof(ob_list); i++) 
		if(environment(ob_list[i]))
		{
			destruct(ob_list[i]);
               }
                      return 1;
                                    }
        }
}
