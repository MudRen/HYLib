// cheng.c

#include <ansi.h>;

inherit NPC;


void create()
{
        set_name("������", ({ "cheng lingsu", "cheng" }));
        set("gender", "Ů��");
        set("age", 24);
        set("long", @long
������ȥ˫ü��������֪����ʲô���£�������òƽƽ���������ڡ�
�����С�����Ŵֲ�������
long);
        set("attitude", "peaceful");
        set("str", 22);
        set("int", 35);
        set("con", 31);
        set("dex", 27);
        set("chat_chance", 10);
        set("chat_msg", ({
                "�����ذ�����̾�˿�����\n",
        }));

        set("qi", 2500);
        set("max_qi", 2500);
        set("jing", 1200);
        set("max_jing", 1200);
        set("neili", 2800);
        set("max_neili", 2800);
        set("jiali", 40);
        set("combat_exp", 400000);
     
        set_skill("force", 150);
        set_skill("duji", 270);
        set_skill("poison", 270);
        set_skill("miaoshouhuichun", 270);

        set("inquiry",([
                "���":     "��...��...\n",
                "Ԭ����":   "��...��������ʲô��\n",
        ]));

        setup();
        carry_object("/clone/cloth/cloth")->wear();
}

