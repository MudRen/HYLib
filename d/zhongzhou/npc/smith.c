#include <ansi.h> 

inherit __DIR__"smithh.c"; 

void create()
{
        set_name("����", ({ "tiejiang", "smith" }));
        set("title", "���е��ϰ�");
        set("shen_type", 1);
        set("gender", "����" );
        set("age", 33);
        set("long", "����������ǯ��סһ����ȵ�����Ž�¯�С�\n");

        set("combat_exp", 400);
        set("attitude", "friendly");
        set("vendor_goods",({
                   "/d/jingzhou/obj/armor",
                   "/d/jingzhou/obj/beixin",
                   "/d/city/npc/obj/jinsijia",
        }));

        setup();

        carry_object("/clone/misc/cloth")->wear();
}
