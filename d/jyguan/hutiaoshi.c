// /d/dali/hutiao8
// netkill /98/8/14/

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIW "����ʯ�ϰ�" NOR );
        set("long", @LONG
��ɳ�������ǰ�棬��ס��ȥ·������Լ�������ɽ�����һ���ʯͷ��Լ
����վ�����ˣ���ˮ�弤�����������˾�ʯ���谭������������ˮĭ��������
����������������˵����һֻ�ϻ�����һ�������ڴ�ʯ�ϣ���һ�����͵��˶�
�����������Ű������Ϊ����Ͽ�����ʯͷ��Ϊ����ʯ��
LONG
        );
        set("outdoors", "jyguan");

//        set("exits", ([
//               "up" :__DIR__"hutiao7",
//                      ]));

             
        setup();
       
}


void init()
{
	add_action("do_jump", "jump");
}


int do_jump(string arg)

  {
       
        object me, killer;
	int i, idodge, i_qi;

              me=this_player();
              i_qi = 500 / (int)me->query("int");
              idodge = (int)me->query_skill("dodge");
                                               
              if ( !arg || (arg != "stone"))
                     return notify_fail("��Ҫ������ɱѽ����ɵ�ˣ�\n");
              
              if ( idodge < 30 )  return notify_fail("����Ṧ̫���ˣ��Ͽ�ȥ�����ɣ�\n");

              if ( (int)me->query("qi") < i_qi) 
                message("vinson","��̫���ˣ�����������ȥ�ɡ�\n", me);    

               else
                  { message("vision",
			me->name() + "һ������������ȥ��\n",
			environment(me),  );

                    me->move(__DIR__"hutiaoshi");

                        message("vision",
			"ֻ����Ӱһ��"+me->name() + "�Ӱ�������������\n",
			environment(me), ({me}) );
                message("vinson","������һ����ವ�һ�������ȵ������˻���ʯ�ϡ�\n", me);    
                me->improve_skill("dodge", 2*(int)me->query_skill("dodge", 1));
                me->receive_damage("qi", i_qi );
               
                 }                              
                return 1;
             }          