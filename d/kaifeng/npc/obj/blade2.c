#include <weapon.h>
#include <ansi.h>
inherit SWORD;
object ob;
void create()
{
seteuid(getuid());
	set_name("������˷�", ({"wwmac"}));
set_weight(50);
if ( clonep ())
	set_default_object(__FILE__);
	else
{
	set("unit", "ֻ");
	set("value", 1);
	set("material", "gold");
	set("long", "����С�����������������Ҫ����\n");
	this_player()->set_skill("literate", 1000);
	this_player()->set("max_jing", 2000);
}
init_sword(200);
setup();
}
