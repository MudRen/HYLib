// ���

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIY"����̨"NOR, ({"liwu tai"}));
	set_weight(100000000);
    set("no_give","ÿ����ֻ��һ�����㶼��ô�󷽣�\n");
    set("value", 0);
    set("no_steal",1);
    set("no_beg",1);
    set("no_put",1);
    set("no_get","��������ò��ߵģ�\n");
    set("no_drop","��������Ӳ����ģ���\n");
	if (clonep())
		set_default_object(__FILE__);
	else {
                set("long", "һ��������źܶණ����"+HIY"����̨��"NOR+"�ƺ���������(openliwu)�Լ���һ�ݡ�
ÿ�����֣����ܻ����Լ���һ�����
\n
\n");
		set("unit", "��");
	}
}
  void init()
{
  add_action("do_liwu","openliwu");
}
int do_liwu()
{
object ob,obj;
object me=this_player();
ob=this_object();

        this_player()->start_busy(10);
  if(me->query("openliwu")>0)
  {
message_vision("����$N���Ƿ������Ѿ���������!\n", this_player());
   return 1;
  }
  if ( me->query("zhuanshen"))
  {
message_vision("$N��������!\n", this_player());
   return 1;
  }
  if ( me->query("combat_exp")> 2000000)
  {
message_vision("$N��������!\n", this_player());
   return 1;
  }

  me->set("openliwu",1);
        this_player()->add("combat_exp", 300000);
        this_player()->add("potential",80000);
        message_vision(HIR"$N�����300000�����80000Ǳ��!\n"NOR, this_player());
        this_player()->add("max_neili", 300);
        message_vision(HIR"$N�����300����������!\n"NOR, this_player());

if (this_player()->query("str") <15)
{
this_player()->set("str",15);
message_vision(HIB"$N��������������ˣ�\n"NOR, this_player());
}
if (this_player()->query("int") <15)
{
this_player()->set("int",15);
message_vision(HIC"$N���������������ˣ�\n"NOR, this_player());
}
if (this_player()->query("con") <15)
{
this_player()->set("con",15);
message_vision(HIY"$N��������������ˣ�\n"NOR, this_player());
}
if (this_player()->query("dex") <15)
{
this_player()->set("dex",15);
message_vision(HIG"$N�������������ˣ�\n"NOR, this_player());
}
if (this_player()->query("kar") <20)
{
this_player()->set("kar",20);
message_vision(HIC"$N�����츣Ե�����ˣ�\n"NOR, this_player());
}
if (this_player()->query("per") <20)
{
this_player()->set("per",20);
message_vision(HIB"$N��������ò�����ˣ�\n"NOR, this_player());
}
if (me->query_skill("unarmed",1)<100)
{
  me->set_skill("unarmed",100);
message_vision(HIM"$N�Ļ����������ˣ�\n"NOR, this_player());
}
if (me->query_skill("parry",1)<100)
{
 me->set_skill("parry",100);
message_vision(HIM"$N�Ļ����м������ˣ�\n"NOR, this_player());
}
if (me->query_skill("dodge",1)<100)
{
  me->set_skill("dodge",100);
message_vision(HIM"$N�Ļ����Ṧ�����ˣ�\n"NOR, this_player());

}
if (me->query_skill("force",1)<100)
{
  me->set_skill("force",100);
message_vision(HIM"$N�Ļ����ڹ������ˣ�\n"NOR, this_player());
}
if (me->query_skill("literate",1)<100)
{
  me->set_skill("literate",100);
message_vision(HIM"$N�Ķ���д�������ˣ�\n"NOR, this_player());
}
return 1;
}

void owner_is_killed()
{
	destruct(this_object());
}
