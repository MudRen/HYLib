//Cracked by Roath
// road: /zhongnan/shulin4.c

inherit ROOM;

void create()
{
		  set("short","����");

		  set("long",@LONG
��λ�����ɽ���һ��Ƭ���֣�������Ϊï�ܡ�������䣬ֻ���ý�
��ɳɳ����Ҷ�������ܻ�谵���ģ���ʱ�����չ⴩��Ũ�ܵ�֦ͷ��Ͷ��
���¡�ż��Զ�������޺�����������һ�����ܸС��������ϸ���һ��С����
LONG);

		  set("exits",([ 
		  "south" : __DIR__"shulin5",
		"north" : __DIR__"shulin3",
							 ])
           );
	  set("cost",2);
	  set("outdoors", "zhongnan");

        setup();

}

#include "caiyao.h"

