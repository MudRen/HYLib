// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("������", ({ "miao ruolan", "miao", "ruolan" }));
        set("gender", "Ů��");
        set("title", "���˷�ǧ��");
        set("age", 17);
        set("long", @LONG
һλ������������Ů�������������ˡ�������
���˷�֮Ů��������
LONG );
        set("attitude", "peaceful");
        set("str", 12);
        set("int", 11);
        set("con", 13);
        set("dex", 11);
        set("per", 30);

        set("qi", 300);
        set("max_qi", 300);
        set("combat_exp", 10000);
        set("score", 20000);
        set_skill("literate", 100);

        set("inquiry", ([
                "��ҽ���" : "����һ�����ҵ������ŵģ���ȥ�������ˡ�",
                "��һ��"   : "���������ҵ���һ���������ˣ����ǡ�������",
                "���"     : "����˵����磿���������Ѿ����ɶ��ˡ�",
        ]));

        create_family("��ԭ���", 7, "ǧ��");

        setup();

        carry_object("/d/city/npc/cloth/zi-dress")->wear();
        add_money("silver", 20);
}

void attempt_apprentice(object ob)
{
        command("xixi");
        command("say ���ֲ����书���������ʲô��");
}

