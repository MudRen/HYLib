#include <ansi.h>
inherit NPC;

void create()
{
        set_name(HIR"��̨������"NOR, ({ "leitai fuzeren","leitai ren","ren"  }) );
        set("gender", "����" );
        set("age", 20);  
        set("per", 30);       
        set("str", 30);
        set("dex", 25);
        set("con", 25);
        set("int", 30);  
        set_temp("leitai", 1);           
        set("attitude", "friendly");
        setup();
}


