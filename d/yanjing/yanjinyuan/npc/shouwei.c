#include <ansi.h>
inherit NPC;
void create()
{
set_name("������ʿ",({"wei shi"}));
set("long","�������ݵ���ʿ����ĸߴ�վ���ر�ֱ����.\n");
set("age",20+random(20));
set("combat_exp",100000+random(900000));
set("food",300);
set("water",300);
set("force_factor",20);
set_skill("unarmed",20+random(50));
set_skill("zhongping-qiang",30+random(50));
//map_skill("parry","zhongping-qiang");
map_skill("club","zhongping-qiang");
set_skill("club",50+random(50));
set_skill("dodge",50+random(50));
set_skill("force",50+random(50));
set("force",500);
set_skill("parry",50+random(50));
set("max_force",500);
setup();
carry_object(__DIR__"tongjia")->wear();
carry_object(__DIR__"tongkui")->wear();
carry_object(__DIR__"tongxue")->wear();
carry_object(__DIR__"tiespear")->wield();
}
int accept_fight(object who)
{
command("say ��������������㡣\n");
return 0;
}
