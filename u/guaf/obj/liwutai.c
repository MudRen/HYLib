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
��������:ÿ����ҿ��Եõ�500000�����300000Ǳ�ܣ�����20���������ԣ�ȫ������20��
����120���ĳ��û����书��ȫ�����㵽120��,�����������ģ�����ɱ����300(���ȼ�1000)��
��������µģ����ӷ�����300(���ȼ�1500)��ת������������5M)����ҿɻ��2��ħ
��(���),4�ű�ʯ(���)�����⣬������ϵĲ������Խ��ᱻ���:���վ�,�����ϲᣬ������
��,˫�ֻ���,������Ĺ,PK�����,��ʦ�����ᱻ���㡣��ҵ���������Ҳ�����380�㡣\n
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
  me->set("openliwu",1);
        this_player()->add("combat_exp", 500000);
        this_player()->add("potential",300000);
        message_vision(HIR"$N�����500000�����300000Ǳ��!\n"NOR, this_player());
        this_player()->add("max_neili", 380);
        message_vision(HIR"$N�����380����������!\n"NOR, this_player());
if (this_player()->query("str") <20)
{
this_player()->set("str",20);
message_vision(HIB"$N��������������ˣ�\n"NOR, this_player());
}
if (this_player()->query("int") <20)
{
this_player()->set("int",20);
message_vision(HIC"$N���������������ˣ�\n"NOR, this_player());
}
if (this_player()->query("con") <20)
{
this_player()->set("con",20);
message_vision(HIY"$N��������������ˣ�\n"NOR, this_player());
}
if (this_player()->query("dex") <20)
{
this_player()->set("dex",20);
message_vision(HIG"$N�������������ˣ�\n"NOR, this_player());
}
if (this_player()->query("kar") <20)
{
this_player()->set("kar",20);
message_vision(HIC"$N��������������ˣ�\n"NOR, this_player());
}
if (this_player()->query("per") <20)
{
this_player()->set("per",20);
message_vision(HIB"$N��������ò�����ˣ�\n"NOR, this_player());
}
if (me->query_skill("unarmed",1)<120)
{
  me->set_skill("unarmed",120);
message_vision(HIM"$N�Ļ����������ˣ�\n"NOR, this_player());
}
if (me->query_skill("parry",1)<120)
{
 me->set_skill("parry",120);
message_vision(HIM"$N�Ļ����м������ˣ�\n"NOR, this_player());
}
if (me->query_skill("dodge",1)<120)
{
  me->set_skill("dodge",120);
message_vision(HIM"$N�Ļ����Ṧ�����ˣ�\n"NOR, this_player());

}
if (me->query_skill("force",1)<120)
{
  me->set_skill("force",120);
message_vision(HIM"$N�Ļ����ڹ������ˣ�\n"NOR, this_player());
}
if (me->query_skill("literate",1)<120)
{
  me->set_skill("literate",120);
message_vision(HIM"$N�Ķ���д�������ˣ�\n"NOR, this_player());
}
if (me->query("weapon/lv") &&
me->query("weapon/lv",1)<100)
{
  me->add("weapon/lv",30);
if (me->query("weapon/lv",1)>100)
me->set("weapon/lv",100);
message_vision(HIW"$N�����������ȼ����������ˣ�\n"NOR, this_player());
}
if (me->query("jia/lv")&&
me->query("jia/lv",1)<150)
{
  me->add("jia/lv",30);
if (me->query("jia/lv",1)>150)
me->set("jia/lv",150);
message_vision(HIW"$N��������µȼ����������ˣ�\n"NOR, this_player());
}

me->delete("szj/failed");
message_vision(HIG"$N�ٴλ���ƽ����վ��Ļ��ᣡ\n"NOR, this_player());
me->delete("jiuyin/shang-failed");
message_vision(HIG"$N�ٴλ�ý�����ϲ�Ļ��ᣡ\n"NOR, this_player());
me->delete("jiuyin/xia-failed");
message_vision(HIG"$N�ٴλ�ý�����²�Ļ��ᣡ\n"NOR, this_player());
me->delete("zhou/fail");
message_vision(HIG"$N�ٴλ�ý�˫�ֻ����Ļ��ᣡ\n"NOR, this_player());
me->delete("jiuyin/gumu-failed");
message_vision(HIG"$N�ٴλ�ý������Ĺ�Ļ��ᣡ\n"NOR, this_player());
me->set("PKS",0);
message_vision(HIG"$N��PK��������㣡\n"NOR, this_player());
me->set("betrayer",0);
message_vision(HIG"$N����ʦ�������㣡\n"NOR, this_player());
me->delete("last_getzhen");
message_vision(HIG"$N�ٴλ��������Ļ��ᣡ\n"NOR, this_player());
if (me->query("zhuanshen")||
me->query("combat_exp") > 5000000)
{
obj=new("/clone/gem/ring"+random(10));
obj->move(me);
message_vision(HIG"$N���һ��ħ�䣡\n"NOR, this_player());
obj=new("/clone/gem/ring"+random(10));
obj->move(me);
message_vision(HIG"$N���һ��ħ�䣡\n"NOR, this_player());
obj=new("clone/gem/gem");
obj->move(me);
message_vision(HIG"$N���һ��ħ����ʯ��\n"NOR, this_player());
obj=new("clone/gem/gem");
obj->move(me);
message_vision(HIG"$N���һ��ħ����ʯ��\n"NOR, this_player());
obj=new("clone/gem/gem");
obj->move(me);
message_vision(HIG"$N���һ��ħ����ʯ��\n"NOR, this_player());
obj=new("clone/gem/gem");
obj->move(me);
message_vision(HIG"$N���һ��ħ����ʯ��\n"NOR, this_player());
}
message("channel:chat", HIG"������ҥ�ԡ���˵"+me->name() + "�����������Լ������!"NOR"��\n", users());
	return 1;
}

void owner_is_killed()
{
	destruct(this_object());
}
