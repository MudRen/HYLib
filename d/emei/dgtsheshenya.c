//Room: dgtsheshenya.c �ù�̨������
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","�ù�̨������");
      set("long",@LONG
�������ֳ����������ǿ��ճ����ƺ�����⡢���֮�ء�̨���������ɣ�
�����޵ף��������ڡ���Ŀ��������������Ĵ�Сѩɽ��������Ŀ����Ϊ����
�������࣬�������棬���������ã�������������Ͷ���ƺ��������������
�������ƺ�������ãã��������Ұ��Զ����ʡ��ƺ��ᵴʱ�����ڽ𶥣���
̤���ƣ�����ƮƮ����֮�У�������Ѹ��ӿ��ʱ�������𶥶�������ǰ������
�����г�������֮�⡣
LONG);
      set("outdoors", "emei");
      set("exits",([ /* sizeof() == 1 */
          "enter"    : __DIR__"woyunan",
          "east"     : __DIR__"duguangtai", 
      ]));
      set("no_clean_up", 0);
      setup();
}
void init()
{
   object me;
   if( interactive( me = this_player())) remove_call_out("clone_ji");
       call_out("clone_ji", 2,me);
   add_action("do_sheshen","sheshen");
}
void clone_ji(object me)
{
   object *ob,obj;
   int i,j;

   if (!me)  return notify_fail("���Ѿ������ˣ�\n");

   j=0;
   ob = all_inventory(environment(me));
   for(i=0; i<sizeof(ob); i++)
   {
      if ( (!userp(ob[i])) && ((string)ob[i]->query("id")=="ji xiaofu"))
      j=1;
   }
   if (!me)  return notify_fail("���Ѿ������ˣ�\n");
   if (!this_object())  return notify_fail("���Ѿ������ˣ�\n");
   if ((j==0) && (me->query("marks/ji")))
   {
      if( environment(me) == this_object()) obj=new("/kungfu/class/emei/ji.c");
if (!obj)   return notify_fail("���Ѿ������ˣ�\n");
if (environment(me))
{
      obj->move(environment(me));
}
   }
}
int do_sheshen(object me)
{
	object *inv,kicker;
	int sizeinv,n,tt;

    me = this_player();
   if (!me)  return notify_fail("���Ѿ������ˣ�\n");
   if (me->query("combat_exp") < 500000)  return notify_fail("������书������ȥ�϶�����\n");
		inv=all_inventory(me);
		sizeinv=sizeof(inv);
	
		while (sizeinv--)
		{
       			if (inv[sizeinv]->is_character()  )  
     				return notify_fail("������ȥ�����˿ڣ�\n");
       		
		}

    message_vision("$N���û���̫û��˼�ˣ�����������ʡ�\n", me);
    message_vision("$N��Ȼ���������£�������У������������쳹ɽ�ȣ�����$N�ĵ�����Ҳ��������������\n", me);
    if (random(4)<1)
    {
        me->move(__DIR__"st0");
        me->unconcious();
    }
    else
    {
        command("chat ����������������ɱ�ˡ�\n\n");
//        me->move(__DIR__"st0");
        me->die();
    }
    return 1;
}

