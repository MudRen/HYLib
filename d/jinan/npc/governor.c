 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
int yuefei();
int leave();
void create()
{
    set_name("������", ({ "master yin", "master","yin" }) );
    set("long",
        "���ϳ�����ߵĹ٣����������ϵ�Ȩ��\n");
    set("nickname", RED"��ͼ���ѧʿ"NOR);
    set("class","official");
    set("attitude", "heroism");
    set("reward_npc", 1);
        set("difficulty", 35);
        set("chat_chance", 1);
        set("chat_msg", ({
                "�������������ϵ���͸��ҵ��з����������ˡ�����\n",
                "������ҡҡͷ�������������ˣ�û�������ѧ��������\n",
        }) );
    // Make this before create_family will prevent generation in title
    set("rank_nogen",1);
    create_family("��͢����",6,"̫��̫�� �ؼ��ϸ�");
    set("student_title","��Ա");
    set("ranks",({ "׼����","����","����","��ͳ��","ͳ��","��Ӫ��ͳ��",
                       "��Ӫͳ��","��Ӫ��ͳ��","���������ᶼָ��ʹ","�����������ᶼָ��ʹ",
                       "�����׾��������ݺ�","�����׾�������ݺ�",RED"��ǰ���ݺ�"NOR,
                       CYN"�����׾�������ָ��ʹ"NOR,YEL"�����׾������ָ��ʹ"NOR,BLU"��ǰ��ָ��ʹ"NOR,
                       CYN"�����׾�������ָ��ʹ"NOR,YEL"�����׾������ָ��ʹ"NOR,RED"��ǰ��ָ��ʹ"NOR }));
    set("rank_levels",({ 32000,64000,128000,256000,384000,
                             512000,800000,1024000,1556000,
                             2048000,3652000,5000000,
                             6258000,8848000,10800000,
                             14580000,20048000,26244000 })); 

    set("vendetta_mark", "authority");
    set("str", 50+random(10));
    set("cor", 40);
    set("cps", 25);
    set("agi",25);
    set("int",30);
/*    set("max_qi",7000);
    set("max_gin",5000);
    set("max_sen",5000); */
    set("max_force",2000);
    set("force",2000);
    set("eff_force",2000);
        set("age",55);
    set("chat_chance_combat", 20);
    set("chat_msg_combat", ({
        (: perform_action, "unarmed.yuhuan" :),
            }) );
    set("combat_exp", 90000000);
    set_temp("apply/damage",500);
    set_skill("unarmed", 220);
    set_skill("force",180);
    set_skill("parry", 160);
    set_skill("dodge", 150);
    set_skill("changquan",220);

        set_temp("apply/attack", 270);
        set_temp("apply/dodge", 270);
        set_temp("apply/parry", 270);
        set_temp("apply/armor", 370);
        set_temp("apply/damage", 300);
    set_skill("literate",140);




    map_skill("unarmed","changquan");



    set("chat_chance_combat", 50);
    set("chat_msg_combat", ({
        (: perform_action, "unarmed.yuhuan" :),
        }) ); 
    setup();
    if(random(4)==2) set("env/no_teach",1);
    carry_object(__DIR__"obj/guanfu")->wear();
} 

void init()
{
        object ob;
        ::init();
        add_action("do_killing", "kill");
        if(interactive(ob = this_player()) && !is_fighting()) {
                remove_call_out("greeting");
                call_out("greeting", 1, this_player());
        }
} 
void greeting(object ob) {
        if(!ob || environment(ob) != environment()) return;
        if (this_object()->query("env/no_teach")==1 && ob->query("family/master_id")=="master yin")
        message_vision("$N�����˵���������з��������Ϸ�����û��˼���㡣��\n",this_object());
}  
int do_killing(string arg)
{
    object player, victim;
    string id,id_class;
    player = this_player();
    if(!arg || arg == "") return 0;
    victim = present(arg, environment(player));
        if(!objectp(victim))
                return notify_fail("����û������ˡ�\n");
    if(living(victim))
    {
        id_class=victim->query("class");
        id=victim->query("id");
        if(id_class == "official"&& userp(victim)&& player!=victim)
        {
            message_vision(HIW
"$N�ȵ����󵨲��񣬾�Ȼ�����Ϸ���ǰ��Ұ���۳�͢����ô��\n"NOR, this_object());
            this_object()->kill_ob(player);
            player->kill_ob(this_object());
            if (!player->is_busy()) player->start_busy(6);
            return 0;
        }
    }
    return 0;
} 
