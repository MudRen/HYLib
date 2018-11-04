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
        if (myskill<me->query_skill("unarmed"))
        myskill=me->query_skill("unarmed");
        if (myskill<me->query_skill("dodge"))
        myskill=me->query_skill("dodge");
        if (myskill<me->query_skill("sword"))
        myskill=me->query_skill("sword");
        if (myskill<me->query_skill("parry"))
        myskill=me->query_skill("parry");
        set_name(HIC "��ǿ��" NOR, ({ me->query("id")+"-qiangdao"}));
        set("title",me->query("name")+"���µ�");
        set("gender", "����");
        set("age", 28);
        set("long", "����һ��ר�����Ӫ����ǿ����\n");
        
        set("attitude", "peaceful");
        set("qi", me->query("max_qi"));
        set("max_qi", me->query("max_qi"));
if ((int)me->query_skill("six-finger",1) >250)
{
        set("qi", me->query("max_qi")+2800);
        set("eff_qi", me->query("max_qi")+2800);
        set("max_qi", me->query("max_qi")+2800);
        set("jing", me->query("max_jing")* 2);
        set("neili", me->query("max_neili")* 2);
        set("max_neili", me->query("max_neili")* 2);
        set("max_jing", me->query("max_jing")* 2);

if (me->query("max_qi")+1800 > 10000)
{
        set("qi", me->query("max_qi"));
        set("eff_qi", me->query("max_qi"));
        set("max_qi", me->query("max_qi"));
}
}
if ((int)me->query_skill("anranxiaohun-zhang",1) >250)
{
        set("qi", me->query("max_qi")+2800);
        set("eff_qi", me->query("max_qi")+2800);
        set("max_qi", me->query("max_qi")+2800);
if (me->query("max_qi")+1800 > 10000)
{
        set("qi", me->query("max_qi"));
        set("eff_qi", me->query("max_qi"));
        set("max_qi", me->query("max_qi"));
}

}

if ((int)me->query_skill("qianzhu-wandushou",1) >250)
{
        set("qi", me->query("max_qi")+2800);
        set("eff_qi", me->query("max_qi")+2800);
        set("max_qi", me->query("max_qi")+2800);
if (me->query("max_qi")+1800 > 10000)
{
        set("qi", me->query("max_qi"));
        set("eff_qi", me->query("max_qi"));
        set("max_qi", me->query("max_qi"));
}

}
if ((int)me->query_skill("tiezhang-zhangfa",1) >250)
{
        set("qi", me->query("max_qi")+1000);
        set("jing", me->query("max_qi")+1000);
        set("eff_jing", me->query("max_jing")+1000);
        set("max_jing", me->query("max_jing")+1000);
        set("eff_qi", me->query("max_qi")+10800);
        set("max_qi", me->query("max_qi")+1000);
if (me->query("max_qi")+1800 > 10000)
{
        set("qi", me->query("max_qi"));
        set("eff_qi", me->query("max_qi"));
        set("max_qi", me->query("max_qi"));
}

}
if ((int)me->query_skill("wudu-goufa",1) >250)
{
        set("qi", me->query("max_qi")+1800);
        set("eff_qi", me->query("max_qi")+1800);
        set("max_qi", me->query("max_qi")+1800);
if (me->query("max_qi")+1800 > 10000)
{
        set("qi", me->query("max_qi"));
        set("eff_qi", me->query("max_qi"));
        set("max_qi", me->query("max_qi"));
}

}

        set("str", me->query("str"));
        set("dex", me->query("dex"));
        set("per", me->query("per"));
        set("con", me->query("str"));

        set("killer",me->query("id"));
        set("combat_exp", me->query("combat_exp"));
// ������5������ǿ���Զ��ߣ���������������˵����ѣ�-��ԲSMILE

        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
           (: perform_action, "unarmed.ji" :),
           (: perform_action, "unarmed.zhan" :),
           (: perform_action, "unarmed.zhenup" :),
           (: perform_action, "sword.lian" :),
           (: perform_action, "sword.chan" :),
            (: perform_action, "sword.sui" :),
           (: random_move :),
        }) );
        set_temp("apply/attack", 80);
        set_temp("apply/defense", 150);
        set_temp("apply/armor", 800);
        set_temp("apply/damage", 100);
      set_skill("dodge", myskill+random(20));
        set_skill("unarmed", myskill);
        set_skill("parry", myskill);
        set_skill("force", myskill);
        set_skill("taiji-shengong", myskill/2+random(100));
        set_skill("taiji-quan", myskill/2+random(100));
        set_skill("taiji-jian", myskill/2+random(100));
        set_skill("tiyunzong", myskill/2+random(100));
        map_skill("dodge", "tiyunzong");
        map_skill("unarmed", "taiji-quan");
        map_skill("sword", "taiji-jian");
        map_skill("parry", "taiji-jian");
        map_skill("force", "taiji-shengong");
if (me->query("combat_exp") > 3500000)
{
//if (random(10)>6)
//{
        set_temp("apply/attack", 100);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 1500);
        set_temp("apply/damage", 100);
        set_skill("tiyunzong", myskill);
//}
        set("chat_chance_combat", 70);
        set("chat_msg_combat", ({
           (: random_move :),
           (: perform_action, "unarmed.ji" :),
           (: perform_action, "unarmed.zhan" :),
           (: perform_action, "unarmed.zhenup" :),
           (: perform_action, "sword.lian" :),
           (: perform_action, "sword.chan" :),
           (: perform_action, "sword.sui" :),
           (: random_move :),
           (: random_move :),
        }) );
}
             set("chat_chance", 80);
             set("chat_msg", ({
              (: random_move :),
             "ǿ����ݺ�˵��: ֪Ȥ�Ŀ�������·Ǯ������ͱ�����Ӳ������ˣ�\n",
              (: random_move :),
              (: random_move :)
        }) );
  

        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/changjian")->wield();

}

void init()
{
        remove_call_out("leave");
        call_out("leave",60);
}

void leave()
{
        object ob = this_object();
        if (!ob->is_fighting()) {
                message_vision(HIC "ǿ�����·�ߵ��Ӳݣ������ˡ�\n" NOR,this_object());
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
        object corpse;      
        int kar, exp, pot;
if (!me) return;
        kar = random(me->query("kar")) * 15;
if (kar >450) kar=450;
//        shen1 =  300+random(100);
//        shen2 =  random(50);
        exp = 600 + kar;
        pot = 300 + random(exp);
if (pot >exp ) pot=exp-50;
if (me)
{
        message_vision(HIR "\nǿ�����ڵ��ϣ������˼��¾����ˡ�\n" NOR,me);
        if (me->query("kill_qiangdao") == 1 && this_object()->query_temp("owner/id") == me->query("id")) {
message("channel:chat",HIG"����������"+me->query("name")+"�ɹ���ɱ��ǿ����Ϊ�������¹��͡�\n"NOR,users());
                  message_vision(HIC "\n����$N�ɹ���ɱ��һ��ǿ������������\n"
                + chinese_number(exp / 3) + "��ʵս���飬\n"
                + chinese_number(pot / 3) + "��Ǳ�ܣ�\n"
                + chinese_number(4) + "��������Ϊ��л��\n" NOR, me);
                me->add("combat_exp", exp / 3);
                me->add("potential", pot / 3);
                me->add("score",4);
                me->delete("quest");
                me->delete("kill_qiangdao");
                }

        corpse = new("/clone/misc/corpse");
        corpse->set("name",HIW "ǿ����ʬ��" NOR);
        corpse->set("long","����һ�������޶�����ǿ����\nȻ�������Ѿ����ˣ�ʣ��һ�߳�ª��ʬ�塣\n");
        corpse->move(environment(this_object()));
        corpse->set_max_encumbrance(1000);        
        me->add("MKS", 1);
}
        destruct(this_object());
}

