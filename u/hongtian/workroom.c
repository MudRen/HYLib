#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "����Ĺ�����");
    set("long", "�õط���\n");

  set("exits", ([ /* sizeof() == 1 */
  "down" : "/u/hxsd/work",
]));
    set("objects",  ([
    __DIR__"long/cao"  :  1,
//    __DIR__"guo/guo"  :  1,
    ]));
set_temp("wayao2",20);
set("pingan",1);
set("sleep_room",1);
  set("valid_startroom", 1);
  set("outdoors", "/u/lywin");

  setup();
}
void init()
{
        mixed *local;
        int  t;
        local = localtime(time()*60);
        t = local[2] * 60 + local[1];       
        add_action("do_look", "look");
}

/*
30-260        ��ҹ
260-510       ����
510-630       �糿
630-810       ����
810-990       ����
990-1170      ����
1170-1360     ����
1360-�ڶ���30 ҹ��
*/

int do_look()
{
        mixed *local;
        int  t;
        local = localtime(time()*60);
        t = local[2] * 60 + local[1];
      
        if( t > 30 && t < 260)
        {
                set("long", BLU"�Ƿ�����ת������Ǩ�ƣ�����ǰ����һ˿�ڰ���������Ҫ������С
�����˯�����ѵĴ��ϣ������õ�������Ѱ�Լ����е���Ů��\n");
        }
        if( t > 260 && t < 510)
        {
                set("long", HIC"���΢�������ݴ�¶����������������Ĺ�������һƬ���ã����峿
�������������͸��������޵�ϣ����\n"NOR);
        }
        if( t > 510 && t < 630)
        {
                set("long", HIY"�������ϰ�����һ����ÿ�õĿ�ʼ�� ���͵ĺ�������������ˣ���Ϊ
��Ϊ�������Լ�,����Ҫȥ�ϰ��ˡ��ϰ�ȥ�!!\n"NOR);
        }
        if( t < 810 && t > 630)
        {
                set("long", HIW"����ĵ����ú��첻�ò�ͣ�������ϵĳ���,�����ﹾ���ҽ�,ʵ����
����ס��,��!�Է�ȥ,���극������ͼ������Ѵ�����ƹ����\n"NOR);
        }
        if( t < 990 && t > 810)
        {
                set("long", HIG"ת�۾͵���Ҫ������ʱ��һ�����͵Ĺ������ڽ�����,���ڻص��ҵ�
����ͼ���Χ����һ��߿�����Ƭ�߳���,�����������޺á�\n"NOR);
        }
        if( t < 1170 && t > 990)
        {
                set("long", HIR"���ں������ƾ���ڵ�λ������,���Ժ��첻�ò���һ����Сʱ��
����,ȥ��������,����,�ɹ�ȴ.......���ڵ��Ϻ�����һ�����ȭ��̨,��
��������Ҿ����һ����㡣��!\n"NOR);
        }
        if( t < 1360 && t > 1170)
        {
                set("long", RED"��ɫ�Ѿ��ܰ��ˣ������ʱ�򣬺������ڵ��˽�ͨ��ѧ,������������
��һ��,̸��˵��.��˵��Ϊ.�������Ӣ��͸�����Ҫ�����ˡ�\n"NOR);
        }
        if( t < 30 || t > 1360)
        {
                set("long", BLU"ҹ���˾��ˣ��������ſ�Ҫ���µ����ӻص��˼�,���˼��Ѿ�������,��
����һ��,��˯��ǰ���ڴ��Ͽ�����С˵�Ǻ�����õ���Ϣ��\n"NOR);
        }
}

varargs int valid_leave(object me, string dir)
{
	object *inv,kicker;
	int sizeinv,n,tt;

        if ( !userp(me))
        {
        write("���Ǳ��˵�����,�㲻�����ߡ�\n");
        write("�㱻�������Ӵ��˳�ȥ��\n");
         me->unconcious();
	return notify_fail("�㲻�ܽ�ȥ!\n");
        }
        else {
		inv=all_inventory(me);
		sizeinv=sizeof(inv);
	
		while (sizeinv--)
		{
       			if (inv[sizeinv]->is_character())  
     				return notify_fail("�����ȥ�����˿ڣ�\n");
       		
		}
        return ::valid_leave(me, dir);
        }
}
