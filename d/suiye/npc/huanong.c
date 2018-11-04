#include <ansi.h>

inherit NPC;
inherit F_DEALER;

void create()
{
        set_name("��ũ", ({ "hua nong", "hua", "nong" }));
        set("title", HIY "��������" NOR); 
        set("gender", "����");
        set("long", "һ���������ص���ũ���������������Ի�\n"
                    "�ֲ���ʮ�꣬�����Ҳ���ڴ��ֻ�������\n"
                    "������һЩ���ӡ�\n");
        set("str", 100);
        set_skill("unarmed", 50);
        set_skill("dodge", 50);
        set_temp("apply/damage", 15);
        set("combat_exp", 800000);
        set("attitude", "friendly");



        set("vendor_goods", ({
        	"/d/city/npc/tea/qimen_hongcha",
        	"/d/city/npc/tea/tie_guanyin",
        	"/d/city/npc/tea/wuyi_yancha",
        	"/d/city/npc/tea/xinyang_maojian",
        	"/d/city/npc/tea/maojian",
        	"/d/city/npc/tea/yinzhen",
        	"/d/city/npc/tea/guapian",
        	"/d/city/npc/tea/maofeng",
        	"/d/city/npc/tea/longjing",
          "/d/city/npc/tea/biluo_chun",
          __DIR__"obj/huazhong",
        }));

        setup();

        carry_object("/clone/misc/cloth")->wear();
        set_max_encumbrance(100000000);
}

void init()
{
        add_action("do_buy", "buy");
        add_action("do_list", "list");
}
