//NPC: /d/lingshedao/npc/liuyun.c
//Creat by Yjss on Sep.1999
#include "ansi.h"
inherit NPC;
inherit F_UNIQUE;
void create()
{
        set_name("����ʹ", ({"liu yun", "liu",}));
        set("long",
        "������ĸߴ�,��ױ���,����͸��һ��а��.\n"
        );
        set("nickname",MAG"��˹�����̻ܽ���ʹ��" NOR);
        set("gender", "����");
        set("attitude", "peaceful");
        set("age", 30);
        set("shen_type",-1);
        set("per", 18);
        set("str", 40);
        set("int", 20);
set_temp("no_kill",1);
        set("con", 30);
        set("dex", 30);

        set("max_qi", 7000);
        set("max_jing", 7200);
        set("neili", 7000);
        set("max_neili", 7000);
        set("jiali", 60);
        set("combat_exp", 1550000);
        set("score",50000);
       
        set_skill("force", 385);
        set_skill("dodge", 385);
        set_skill("lingfa", 385);
        set_skill("parry", 385);
        set_skill("qiankun-danuoyi", 390);
        set_skill("shenghuo-shengong", 380);
        set_skill("shenghuo-ling",385);
        map_skill("force", "shenghuo-shengong");
        map_skill("dodge", "qiankun-danuoyi");
        map_skill("parry", "shenghuo-ling");
        map_skill("sword", "shenghuo-ling");
 
        setup();
        carry_object("/d/mingjiao/obj/baipao")->wear();
        carry_object(__DIR__"obj/shenghuo-ling")->wield();
//        carry_object("/clone/book/shenghuo-ling")->wield();
}


void init()
{
        object ob=this_player();
        if(interactive(ob) && ob->query("party/party_name")== HIG "����" NOR)
    {
        message("vision",HIC"����ʹ����˵��:����ʥ���������ʨ�������¹�ӭ�ӣ�������ʱ?\n\n"NOR,"/d/lingshedao/xiaowu");
        message_vision(HIC"����ʹ���Ŷ�$N����˵��:��������������,���˻���ʹ��,Ϊ�β��¹�?\n\n"NOR,ob);
        tell_object(ob,HIC"������¹�(kneel)���Ǿܾ�(refuse)?\n\n"NOR);
    }
        add_action("do_kneel","kneel");
        add_action("do_refuse","refuse");
}

int do_kneel()
{       
        object tld;
        object ob=this_player();
if (ob && present("tulong dao",ob))
{
        message_vision("$N���������Ĺ��ڵ���,˵��:����"+ob->query("name")+"��ӭ����ʹ��.\n\n",ob);
        message("vision",HIC"����ʹ������Ц,˵��:����,����.���������е���ѵ�,��ʹ�ߵ��ǿ�����,������!\n\n"NOR,"/d/lingshedao/xiaowu");
        message_vision(HIC"˵������ʹ��$N���е����������˹�ȥ.\n\n"NOR,ob);
        tld=present("tulong dao",ob);
if (tld)
{
        tld->move(this_object());
}
}
        call_out("dest",0,ob);
        return 1;
}

int do_refuse()
{
        object ob=this_player();
if (ob)
{
        message_vision(HIC"$N��Ȼ˵��:��������������,���Ҽ��������������,ȴ�������Ǹ���˹����,Ϊ���¹�?\n\n"NOR,ob);
        message_vision(HIC"����ʹ��ɫһ��,ŭ��:��˵�ŵ�,��˵�ŵ�,
���շ������ʶһ�����ǵ���������.\n\n"NOR,ob);
        message_vision(HIC"����ʹ����һ��,�������ʹ,����ʹΧ������,����ʹ��$N���һ��:���а�.\n\n"NOR,ob);
        call_out("fight3",5,ob);
}
        return 1;
}

#include "shi.h"
/*int fight3(object ob)
{       
   say("haha,test\n");
   return 1;
}*/
