// /d/kunming/pubu
// netkill /98/8/14/

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�ƹ������ٲ�");
        set("long", @LONG
�������ӣ�һ���޴���ٲ�Ծ����ǰ��ˮ����ͬ��ɫ�Ĳʳ�һ��
ֱк���������������������ˮ�����������������ֻ������ˬ�ޱȣ�
��ˮ���ĳ��֮�£��ٲ��ײ��γ���һ������׵�ˮ̶������������
��������������ͷ·���������Դһ����
LONG
        );
        set("outdoors", "kunming");
	set("exits", ([
                          "east"      : "/d/guizhou/shanlu3",
		
	]));            
        setup();
       
}


void init()
{
        add_action("do_enter", "poke");
	UPDATE_D->check_user(this_player());
}


int do_enter(string arg)
{
	object me;
	me = this_player();

        if( !arg || arg=="" ) return 0;

        if( arg=="huacong" ) 
	{
		message("vinson", HIY "��ο��������˳�ȥ\n\n" NOR, this_player());

                me->move(__DIR__"yunnan5");
                
		return 1;
	}
}	


