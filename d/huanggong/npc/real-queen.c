#include <ansi.h>
inherit NPC;

void create()
{
        set_name(HIY "��̫��" NOR, ({ "empress","queen"}));
        set("shen_type", 0);
        set("age",43);
        set("gender", "Ů��");
      set("per",24);
        set("long",
                "�����ð������֣�Ҳ�������겻�����⣬����������ɫ�Եúܲ԰ס�\n");
        set("combat_exp", 500);
        set("attitude", "friendly");
        set("inquiry", ([
                "�ݺ�" : "��ʲô��˼......��\n",
        ]));
      
  setup();
//        carry_object("/clone/misc/pink_cloth")->wear();
}
