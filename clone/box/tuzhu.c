#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIB"������"NOR, ({ "tuzhu" }) );
    set_weight(1);
            set("no_put", 1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
	       
            set("no_put", 1);
            set("no_steal", 1);
            set("no_get", 1);
            set("no_beg", 1);
            set("value", 100000);
            set("unit", "��");
            set("material", "paper");
            set("long", "�������(gohome),��(usezhu)���뿪�Թ�����(setzhu)�����ÿռ���λ��\n");
          }

    setup();
}
void init()
{
	add_action("do_eatt", "gohome");
	add_action("do_eat", "usezhu");
	add_action("do_set", "setzhu");
}

int do_set(string arg)
{
	object *inv;
	int sizeinv;
        object me = this_player();
        string target;
 	if (!id(arg))
	return notify_fail("��Ҫ��ʲô��\n");
		inv=all_inventory(me);
		sizeinv=sizeof(inv);
	
		while (sizeinv--)
		{
       			if (inv[sizeinv]->is_character())  
     				return notify_fail("�㲻�ܱ�����������!\n");
       		
		}
    if (me->is_fighting()) 
        return notify_fail("���������������!\n");
    if (me->is_busy()) 
        return notify_fail("������������!\n");
    if (me->query("neili")<1000)
	return notify_fail("�����������!\n");
me->delete("vendetta/authority");
    if(environment(me)->query("short")==BLU"ɽ��"NOR
       ||environment(me)->query("short")==WHT"����ʯ��"NOR
       ||environment(me)->query("short")==YEL"�Ҷ�"NOR
       ||environment(me)->query("short")==RED"���Ҷ�"NOR
       ||environment(me)->query("short")==CYN"ʯ��"NOR
       ||environment(me)->query("magicroom"))
{
        target=(string)file_name(environment(me));
        me->set("jobtarget",target);
        me->start_busy(8);
        message_vision(HIG "$N�԰����ó���һ������������!\n" NOR, me);
        message_vision(HIG "�´�ʹ���������㽫��ֱ����������!\n" NOR, me);
        me->add("neili",-1000);
}	
else 
{
        message_vision(HIG "$N���ﲻ��ʹ��!\n" NOR, me);
}
	return 1;
}


int do_eat(string arg)
{
string msg;
	object *inv;
	int sizeinv;
        object me = this_player();
        object tarset;
 	if (!id(arg))
	return notify_fail("��Ҫ��ʲô��\n");
		inv=all_inventory(me);
		sizeinv=sizeof(inv);
	
		while (sizeinv--)
		{
       			if (inv[sizeinv]->is_character())  
     				return notify_fail("�㲻�ܱ�����������!\n");
       		
		}

    if (me->is_fighting()) 
        return notify_fail("���������������!\n");
    if (me->is_busy()) 
        return notify_fail("������������!\n");
    if (me->query("neili")<1000)
	return notify_fail("�����������!\n");

    if(environment(me)->query("short")==BLU"ɽ��"NOR
       ||environment(me)->query("short")==WHT"����ʯ��"NOR
       ||environment(me)->query("short")==YEL"�Ҷ�"NOR
       ||environment(me)->query("short")==RED"���Ҷ�"NOR
       ||environment(me)->query("short")==CYN"ʯ��"NOR
       ||environment(me)->query("magicroom"))
{
        if (!me->query("jobtarget"))
       {
        me->move("d/city/guangchang");
       }
      else{
      tarset=me->query("jobtarget");
msg=me->query("jobtarget");
    if (me->query_condition("migongmove"))
	return notify_fail("��ո��ù��ƶ��㣬�Ȼ�������!\n");
if (strsrch(msg,"lev19")>1
&& (int)me->query_skill("magic-ice",1) > 10)
{
me->set_temp("jobtar","/d/migong/lev19/dong2"+(random(5)+1));
tarset=me->query_temp("jobtar");
}
if (strsrch(msg,"lev18")>1
&& (int)me->query_skill("magic-earth",1) > 10)
{
me->set_temp("jobtar","/d/migong/lev18/dong2"+(random(5)+1));
tarset=me->query_temp("jobtar");
}
if (strsrch(msg,"lev17")>1
&& (int)me->query_skill("magic-water",1) > 10)
{
me->set_temp("jobtar","/d/migong/lev17/dong2"+(random(5)+1));
tarset=me->query_temp("jobtar");
}
if (strsrch(msg,"lev16")>1
&& (int)me->query_skill("magic-fire",1) > 10)
{
me->set_temp("jobtar","/d/migong/lev16/dong2"+(random(5)+1));
tarset=me->query_temp("jobtar");
}
if (strsrch(msg,"lev14")>1)
{
me->set_temp("jobtar","/d/migong/lev14/dong0"+(random(5)+1));
if (random(3)==1) me->set_temp("jobtar","/d/migong/lev14/dong"+(random(21)+50));
if (random(3)==2) me->set_temp("jobtar","/d/migong/lev14/dong"+(random(21)+30));
tarset=me->query_temp("jobtar");
}
if (strsrch(msg,"lev13")>1)
{
me->set_temp("jobtar","/d/migong/lev13/dong0"+(random(5)+1));
if (random(3)==1) me->set_temp("jobtar","/d/migong/lev13/dong"+(random(21)+50));
if (random(3)==2) me->set_temp("jobtar","/d/migong/lev13/dong"+(random(21)+30));
tarset=me->query_temp("jobtar");
}
if (strsrch(msg,"lev12")>1)
{
me->set_temp("jobtar","/d/migong/lev12/dong0"+(random(5)+1));
if (random(3)==1) me->set_temp("jobtar","/d/migong/lev12/dong"+(random(21)+50));
if (random(3)==2) me->set_temp("jobtar","/d/migong/lev12/dong"+(random(21)+30));
tarset=me->query_temp("jobtar");
}
if (strsrch(msg,"lev11")>1)
{
me->set_temp("jobtar","/d/migong/lev11/dong0"+(random(5)+1));
if (random(3)==1) me->set_temp("jobtar","/d/migong/lev11/dong"+(random(21)+50));
if (random(3)==2) me->set_temp("jobtar","/d/migong/lev11/dong"+(random(21)+30));
tarset=me->query_temp("jobtar");
}
if (strsrch(msg,"lev10")>1)
{
me->set_temp("jobtar","/d/migong/lev10/dong0"+(random(5)+1));
if (random(3)==1) me->set_temp("jobtar","/d/migong/lev10/dong"+(random(21)+50));
if (random(3)==2) me->set_temp("jobtar","/d/migong/lev10/dong"+(random(21)+30));
tarset=me->query_temp("jobtar");
}
if (strsrch(msg,"lev9")>1)
{
me->set_temp("jobtar","/d/migong/lev9/dong0"+(random(5)+1));
if (random(3)==1) me->set_temp("jobtar","/d/migong/lev9/dong"+(random(21)+50));
if (random(3)==2) me->set_temp("jobtar","/d/migong/lev9/dong"+(random(21)+30));
tarset=me->query_temp("jobtar");
}
if (strsrch(msg,"lev8")>1)
{
me->set_temp("jobtar","/d/migong/lev8/dong0"+(random(5)+1));
if (random(3)==1) me->set_temp("jobtar","/d/migong/lev8/dong"+(random(21)+50));
if (random(3)==2) me->set_temp("jobtar","/d/migong/lev8/dong"+(random(21)+30));
tarset=me->query_temp("jobtar");
}
if (strsrch(msg,"lev7")>1)
{
me->set_temp("jobtar","/d/migong/lev7/dong0"+(random(5)+1));
if (random(3)==1) me->set_temp("jobtar","/d/migong/lev7/dong"+(random(21)+50));
if (random(3)==2) me->set_temp("jobtar","/d/migong/lev7/dong"+(random(21)+30));
tarset=me->query_temp("jobtar");
}
if (strsrch(msg,"lev6")>1)
{
me->set_temp("jobtar","/d/migong/lev6/dong0"+(random(5)+1));
if (random(3)==1) me->set_temp("jobtar","/d/migong/lev6/dong"+(random(21)+50));
if (random(3)==2) me->set_temp("jobtar","/d/migong/lev6/dong"+(random(21)+30));
tarset=me->query_temp("jobtar");
}
if (strsrch(msg,"lev5")>1)
{
me->set_temp("jobtar","/d/migong/lev5/dong0"+(random(5)+1));
if (random(3)==1) me->set_temp("jobtar","/d/migong/lev5/dong"+(random(21)+50));
if (random(3)==2) me->set_temp("jobtar","/d/migong/lev5/dong"+(random(21)+30));
tarset=me->query_temp("jobtar");
}
if (strsrch(msg,"lev4")>1)
{
me->set_temp("jobtar","/d/migong/lev4/dong0"+(random(5)+1));
if (random(3)==1) me->set_temp("jobtar","/d/migong/lev4/dong"+(random(21)+50));
if (random(3)==2) me->set_temp("jobtar","/d/migong/lev4/dong"+(random(21)+30));
tarset=me->query_temp("jobtar");
}
if (strsrch(msg,"lev3")>1)
{
me->set_temp("jobtar","/d/migong/lev3/dong0"+(random(5)+1));
if (random(3)==1) me->set_temp("jobtar","/d/migong/lev3/dong"+(random(21)+50));
if (random(3)==2) me->set_temp("jobtar","/d/migong/lev3/dong"+(random(21)+30));
tarset=me->query_temp("jobtar");
}if (strsrch(msg,"lev2")>1)
{
me->set_temp("jobtar","/d/migong/lev2/dong0"+(random(5)+1));
if (random(3)==1) me->set_temp("jobtar","/d/migong/lev2/dong"+(random(21)+50));
if (random(3)==2) me->set_temp("jobtar","/d/migong/lev2/dong"+(random(21)+30));
tarset=me->query_temp("jobtar");
}
if (strsrch(msg,"lev20")>1
&& (int)me->query_skill("magic-light",1) > 10)
{
me->set_temp("jobtar","/d/migong/lev20/dong2"+(random(5)+1));
tarset=me->query_temp("jobtar");
}
if (strsrch(msg,"lev21")>1
&& (int)me->query_skill("magic-dark",1) > 10)
{
me->set_temp("jobtar","/d/migong/lev21/dong2"+(random(5)+1));
tarset=me->query_temp("jobtar");
}

      me->move(tarset);
me->apply_condition("migongmove",18);
      message_vision(HIG "$N�԰����ó���һ������������!\n" NOR, me);
      }
        me->start_busy(8);
        message_vision(HIG "$N�԰����ó���һ������������!\n" NOR, me);
        me->add("neili",-1000);
	destruct(this_object());
}	
else 
{
        message_vision(HIG "$N���ﲻ��ʹ��!\n" NOR, me);
}
	return 1;
}

int do_eatt(string arg)
{
	object *inv;
	int sizeinv;
        object me = this_player();
        object tarset;
 	if (!id(arg))
	return notify_fail("��Ҫ��ʲô��\n");
		inv=all_inventory(me);
		sizeinv=sizeof(inv);
	
		while (sizeinv--)
		{
       			if (inv[sizeinv]->is_character())  
     				return notify_fail("�㲻�ܱ�����������!\n");
       		
		}

    if (me->is_fighting()) 
        return notify_fail("���������������!\n");
    if (me->is_busy()) 
        return notify_fail("������������!\n");

    if(environment(me)->query("short")==BLU"ɽ��"NOR
       ||environment(me)->query("short")==WHT"����ʯ��"NOR
       ||environment(me)->query("short")==YEL"�Ҷ�"NOR
       ||environment(me)->query("short")==RED"���Ҷ�"NOR
       ||environment(me)->query("short")==CYN"ʯ��"NOR
       ||environment(me)->query("magicroom"))
{
me->apply_condition("migongmove",18);
        me->move("d/migong/migong3");
        me->start_busy(8);
        message_vision(HIG "$N�԰����ó���һ������������!\n" NOR, me);
	destruct(this_object());
}	
else 
{
        message_vision(HIG "$N���ﲻ��ʹ��!\n" NOR, me);
}
	return 1;
}
