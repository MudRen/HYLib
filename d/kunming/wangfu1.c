// /d/kunming/wangfu1
// netkill /98/9/11/


#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",  "������Ժ" );
        set("long", @LONG
�������ƽ�������Ĵ�Ժ��Ժ�������˸��ӻ��ݣ������۵�ȴ���м��
һ������ɽ�裬�޴�������Ͽ�����������ɽ�軨����ɫ��ǳ��һ�������
�죬ʮ�ֺÿ���
LONG
        );
          set("outdoors", "kunming");

        set("exits", ([
                "south"    :__DIR__"wangfu",
		"north"   :__DIR__"wangfu2",
		"west"   :__DIR__"xizoulang",
		"east"   :__DIR__"dongzoulang"
                
        ]));

        setup();
	replace_program(ROOM);	       
}
	  		