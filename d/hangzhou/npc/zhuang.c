//Cracked by Kafei
// /d/hangzhou/npc/zhuang.c
// by aln  2 / 98

inherit NPC;

#include <ansi.h>

string ask_book();

void create()
{
        set_name("ׯ�ʳ�", ({ "zhuang yuncheng" , "zhuang" }));
        set("gender", "����");
        set("age", 65);
        set("long", 
"�����������ĸ���������������\n"       
"�����˰���֮�ţ����빤������ӡ�����鼭�ԡ���\n");
        set("shen_type", 1);
        set("combat_exp", 200);

        set("str", 20);
        set("int", 30);
        set("con", 20);
        set("dex", 20);

        set("max_qi", 100);
        set("max_jing", 100);

        set("score", 100);

        set_skill("dodge", 10);

        set("inquiry", ([
                 "�����鼭�ԡ�" : (: ask_book :),
		 "���鼭��" : (: ask_book :),
                 "book" : (: ask_book :),
        ]));

        setup();
        carry_object("/clone/cloth/cloth")->wear();
}

string ask_book()
{
        object ob, me = this_player();

        if( time() < (int)me->query("mh_time") + 1200 )
                return RANK_D->query_respect(me) + "���Ǹ��ʹ�����";

        if( (int)me->query_skill("literate", 1) < 30 )
                return RANK_D->query_respect(me) + "�ֲ�ʶһ����Ҫ����θɣ�";

//	return 0;
        command("nod");
        me->set("mh_time", time());
        ob = new(__DIR__"mh_book");
        ob->move(me);
        message_vision("$N��һ" + ob->query("unit") + ob->name() + "����$n��\n", this_object(), me);
        return "���˹���֮�����������ˡ������������������������׫��";
}
