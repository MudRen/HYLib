// Obj /d/ruzhou/npc/obj/jiuxi.c
// llm 99/07/09

inherit ITEM;
#include <ansi.h>

void create()
{
	set_name("��ϯ", ({ "jiuxi" }));
   if( clonep() )
       set_default_object(__FILE__);
   else
   {
		set("long", "����һ����ɫ��ȫ����ζ���硢��ʢ�ľ�ϯ��\n"
   HIG"��ζƴ��(pingpan)  ��Ʒ꽸�(guogeng)  �������(tipang)\n"
      "���ӹ���(guiyu)    �㹽����(caixing)  ��������(jiayu)\n"
      "�˲μ���(jitang)   ���񶹸�(doufu)    ������з(qingxie)\n"NOR);
		set("unit", "��");
		set("value",1000);
set("no_drop",1);
      set("no_get","��Ҳ̫�����˰ɣ����뿸����һ���ľ�ϯ��Ū�ö���\n");
   }
   setup();
}

void init()
{
	add_action("do_eat", "eat");
}

int do_eat(string arg)
{
	object me=this_player();
   if( me->is_busy() )
      return notify_fail("����һ��������û����ɡ�\n");
   if((int)me->query("food")>=(int)me->max_food_capacity() )
	   return notify_fail("���Ѿ���̫���ˣ������ʲô��\n");
	switch(arg)
   {
   	case "pingpan":
         message_vision("$N��������һ��ƴ����ˣ��н���������ζ�ؽ�������\n",me);
	   	me->add("food",8);
         if((int)me->query("water")< (int)me->max_water_capacity())
		   	me->add("water",1);
         break;
      case "guogeng":
      	message_vision("$NҨ��һ����Ʒ��������������������������\n",me);
	   	me->add("food",2);
         if((int)me->query("water")< (int)me->max_water_capacity())
		   	me->add("water", 8);
         break;
      case "tipang":
      	message_vision("$N����һ���ĺ���������̻��ʵس�����ȥ��\n",me);
	   	me->add("food",20);
         if((int)me->query("water")< (int)me->max_water_capacity())
		   	me->add("water", 2);
         break;
      case "guiyu":
      	message_vision("$N�г�һ�����ӹ��㣬ֻ�����컬�ۣ������ޱȡ�\n",me);
	   	me->add("food",10);
         if((int)me->query("water")< (int)me->max_water_capacity())
		   	me->add("water", 2);
         break;
      case "caixing":
      	message_vision("$Nϸ�ĵ�����һЩɫ���ȫ���㹽���ģ�������Ʒζ�ţ����㡣\n",me);
	   	me->add("food",10);
         if((int)me->query("water")< (int)me->max_water_capacity())
		   	me->add("water", 2);
         break;
      case "jiayu":
      	message_vision("$Nһ�����ڳ�һ����㣬�������͵��������\n",me);
	   	me->add("food",20);
         if((int)me->query("water")< (int)me->max_water_capacity())
		   	me->add("water", 4);
         break;
      case "jitang":
      	message_vision("$N������ζ���س���һ���˲μ����������������ޱȡ�\n",me);
	   	me->add("food",2);
         if((int)me->query("water")< (int)me->max_water_capacity())
		   	me->add("water",15);
         break;
      case "doufu":
      	message_vision("$N����һ����񶹸��������һ�����Ҹ���������顣\n",me);
	   	me->add("food",8);
         if((int)me->query("water")< (int)me->max_water_capacity())
		   	me->add("water", 1);
         break;
      case "qingxie":
      	message_vision("$N����ͷ��������з�ǣ�һ��һ�ڵ�˱������������֭�⡣\n",me);
	   	me->add("food",10);
         if((int)me->query("water")< (int)me->max_water_capacity())
		   	me->add("water", 1);
         break;
      default:
      	write("�����ʲô��������ô��˶����ԣ�\n");
         break;
   }
	return 1;
}
