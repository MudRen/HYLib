#include <ansi.h>
inherit NPC;

void create()
{
        set_name("�콭", ({ "xiaojiang" }) );
        set("gender", "Ů��" );
        set("age", 22);
        set("long","�콭�չˣ���޸�һС������������������Ϳ�ʹÿ�챳һ��С�����������磩����\n");
        set("combat_exp", 5);
        set("chat_chance", 15);
        set("chat_msg", ({
                (: random_move :)
        }) );
        set("attitude", "friendly");
        setup();
        carry_object("/clone/misc/cloth")->wear(); 
} 
