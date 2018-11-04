// qiangdao.c ǿ��
// lag.2000/3/17

inherit NPC;
#include <ansi.h>
void move();

void create()
{       object me;
        int myskill;
        me=this_player();
        myskill=me->query_skill("force");
        set_name(HIC "����Ľ����ͽ����" NOR, ({ me->query("id")+"-pantu"}));
        set("title",me->query("name")+"���µ�");
        set("gender", "����");
        set("age", 28);
        set("long", "����һ������Ľ����ͽ��\n");
        
        set("attitude", "peaceful");
        set("qi", me->query("qi"));
        set("max_qi", me->query("max_qi"));
        set("jing", me->query("jing"));
        set("neili", me->query("neili"));
        set("max_neili", me->query("max_neili"));
        set("max_jing", me->query("max_jing"));
        set("str", me->query("str"));
        set("dex", me->query("dex"));
        set("per", me->query("per"));
        set("killer",me->query("id"));
        set("combat_exp", me->query("combat_exp"));
// ������5������ǿ���Զ��ߣ���������������˵����ѣ�-��ԲSMILE
        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: perform_action, "parry.yihuajiemu" :),
                (: perform_action, "parry.xingyi" :),
                (: perform_action, "finger.dianxue" :),
                (: perform_action, "finger.dianxue" :),
                (: perform_action, "sword.kuangjian" :),
                (: perform_action, "sword.qixing" :),
                (: perform_action, "sword.lianhuan" :),
                (: perform_action, "dodge.yanling" :),                
                (: perform_action, "dodge.yanling" :),                
        }));
             set("chat_chance", 30);
             set("chat_msg", ({
              (: random_move :)
        }) );


        set_skill("hand", myskill * 3 / 4);
        set_skill("staff", myskill * 3 / 4);
        set_skill("dodge", myskill * 3 / 4);
        set_skill("finger", myskill * 3 / 4);
        set_skill("sword", myskill * 3 / 4);
        set_skill("unarmed", myskill* 3 / 4);
        set_skill("parry", myskill* 3 / 4);
        set_skill("force", myskill* 3 / 4);
        set_skill("blade", myskill* 3 / 4);
        set_skill("strike", myskill* 3 / 4);
        set_skill("xingyi-zhang", myskill* 3 / 4);
        set_skill("canhe-zhi", myskill* 3 / 4);
        set_skill("murong-jianfa", myskill* 3 / 4);
        set_skill("shenyuan-gong", myskill* 3 / 4);
        set_skill("yanling-shenfa", myskill* 3 / 4);
        set_skill("douzhuan-xingyi", myskill* 3 / 4);
        map_skill("blade", "murong-daofa");
        map_skill("finger", "canhe-zhi");
	map_skill("force", "shenyuan-gong");
	map_skill("dodge", "yanling-shenfa");
        map_skill("parry", "douzhuan-xingyi");
	map_skill("sword", "murong-jianfa");

	prepare_skill("finger","canhe-zhi");
        set_temp("apply/attack", 100);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 200);
        set_temp("apply/damage", 250);
        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/gangjian")->wield();

}

void init()
{
        remove_call_out("leave");
        call_out("leave",120);
}

void leave()
{
        object ob = this_object();
        if (!ob->is_fighting()) {
                message_vision(HIC "����Ľ����ͽ�������·�ߵ��Ӳݣ������ˡ�\n" NOR,this_object());
                destruct(this_object());
                }
        else call_out("leave",30);
}
void unconcious()
{
    die();
}

void die()
{
        object me = this_object()->query_temp("last_damage_from");
        object corpse,zhi;      

if (me)
{

        message_vision(HIR "\n����Ľ����ͽ���ڵ��ϣ������˼��¾����ˡ�\n" NOR,me);
        message_vision(HIG "\n�����ͽ�������ҵ��˴��ഫ��������\n" NOR,me);
        if (me->query("kill_mr") == 1 && this_object()->query_temp("owner/id") == me->query("id")) {
               zhi=new(__DIR__"zhi");
               zhi->set("byname",me->query("name"));
               zhi->move(me);
                me->add("score",2);
                }

        corpse = new("/clone/misc/corpse");
        corpse->set("name",HIW "����Ľ����ͽ��ʬ��" NOR);
        corpse->set("long","����һ�������޶����Ĺ���Ľ����ͽ��\nȻ�������Ѿ����ˣ�ʣ��һ�߳�ª��ʬ�塣\n");
        corpse->move(environment(this_object()));
        corpse->set_max_encumbrance(1000);        
        me->add("MKS", 1);
}
        destruct(this_object());
}


