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
        set_name(HIC "ǿ��" NOR, ({ me->query("id")+"-qiangdao"}));
        set("title",me->query("name")+"���µ�");
        set("gender", "����");
        set("age", 28);
        set("long", "����һ��ר�����Ӫ����ǿ����\n");
        
        set("attitude", "peaceful");
        set("qi", me->query("qi"));
        set("max_qi", me->query("max_qi"));
        set("jing", me->query("jing")*3/6);
        set("neili", me->query("neili"));
        set("max_neili", me->query("max_neili"));
        set("max_jing", me->query("max_jing")*3/6);
        set("str", me->query("str"));
        set("dex", me->query("dex"));
        set("per", me->query("per"));
        set("killer",me->query("id"));
        set("combat_exp", me->query("combat_exp"));
           set("chat_chance", 80);
                set("chat_msg", ({
                "ǿ����ݺ�˵��: ֪Ȥ�Ŀ�������·Ǯ������ͱ�����Ӳ������ˣ�\n",
                      (: random_move :)
                                                     }) );
        set_skill("dodge", myskill);
        set_skill("unarmed", myskill);
        set_skill("force", myskill);
        set_skill("taiji-quan", myskill);
        set_skill("taiji-jian", myskill);
        set_skill("tiyunzong", myskill);
        map_skill("dodge", "tiyunzong");
        map_skill("unarmed", "taiji-quan");
        map_skill("sword", "taiji-jian");
        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/changjian")->wield();

}

void init()
{
        remove_call_out("leave");
        call_out("leave",30);
}

void leave()
{
        object ob = this_object();
        if (!ob->is_fighting()) {
                message_vision(HIC "ǿ�����·�ߵ��Ӳݣ������ˡ�\n" NOR,this_object());
                destruct(this_object());
                }
        else call_out("leave",10);
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
//        shen1 =  300+random(100);
//        shen2 =  random(50);
        exp = 500 + kar;
        pot = 350 + random(exp);

        message_vision(HIR "\nǿ�����ڵ��ϣ������˼��¾����ˡ�\n" NOR,me);
        if (me->query("kill_qiangdao") == 1 && this_object()->query_temp("owner/id") == me->query("id")) {

                message_vision(HIC "\n����$N�ɹ���ɱ��һ��ǿ������ʦ����������\n"
                + chinese_number(exp / 5) + "��ʵս���飬\n"
                + chinese_number(pot / 5) + "��Ǳ�ܣ�\n"
                + chinese_number(2) + "��������Ϊ��л��\n" NOR, me);
                me->add("combat_exp", exp / 5);
                me->add("potential", pot / 5);
                me->add("score",2);
                me->delete("quest");
                me->delete("kill_qiangdao");
                }

        corpse = new("/d/city/obj/corpse");
        corpse->set("name",HIW "ǿ����ʬ��" NOR);
        corpse->set("long","����һ�������޶�����ǿ����\nȻ�������Ѿ����ˣ�ʣ��һ�߳�ª��ʬ�塣\n");
        corpse->move(environment(this_object()));
        corpse->set_max_encumbrance(1000);        
        me->add("MKS", 1);

        destruct(this_object());
}

