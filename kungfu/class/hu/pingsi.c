#include <ansi.h>

inherit NPC;


int ask_job();
int ask_fail();
mixed ask_me();

void create()
{
        set_name("ƽ��", ({ "ping si", "ping", "si" }));
        set("gender", "����");
        set("age", 65);
        set("title", "������Ӷ");
        set("long", "���Ǻ������Ĺ��������ۡ�\n");
        set("attitude", "peaceful");
        set("str", 20);
        set("int", 20);
        set("con", 24);
        set("dex", 20);

        set("max_qi", 4000);
        set("max_jing", 1000);
        set("neili", 3000);
        set("max_neili", 3000);
        set("combat_exp", 150000);

        set_skill("force", 40);
        set_skill("blade", 40);
        set_skill("dodge", 40);
        set_skill("parry", 40);
        set_skill("unarmed", 40);

        create_family("�������", 0, "��Ӷ");

        set("inquiry",([
        	"�ֻ�"   : "�ֻ����ߡ����������",
                "��һ��" : "�ǡ������������ˣ�����",
                "���˷�" : "������ɲ��ǻ��ˡ�",
                "�԰�ɽ" : "�����Ҽ����˵Ľ�������û��˵�ġ�",
        ]));
        set("coagents", ({
                ([ "startroom" : "/d/guanwai/xiaowu",
                   "id"        : "hu fei" ]),
        }));

        setup();
        set("startroom", "/d/guanwai/xiaoyuan");
        carry_object("/clone/cloth/cloth")->wear();
}

