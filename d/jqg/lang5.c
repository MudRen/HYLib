// lang5.c ����
// By River 99/05/20
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", HIY"���᳤��"NOR);
        set("long",@LONG
ת����������ѵ����᳤�ȵľ�ͷ��������ӵ�ϸխ���ԣ���ͷ�Ĵ�ˮ
�����˶پ���Ȼ���ʣ����Ӽ�����ΧȦ�Թ�ɫ�����ש�ߣ�������Ʈ�ݵ���
���������ɾ�����ζ�����л�������������Ӳӵģ���Ծ�ǳ������ӵı���
�ǽ��ң�������֥����ɢ����һ�����������㡣
LONG
    );

        set("exits",([
           "north": __DIR__"jianshi",
           "south": __DIR__"zhifang",
           "east": __DIR__"lang4",
        ]));
        setup();
}

void init()
{
        object me = this_player();
        if(me->query_temp("jqg/enter")){
          me->delete_temp("jqg/enter");
          }
}

int valid_leave(object me, string dir)
{
        if ( !me->query_temp("gsz_agree")
           && dir !="east")
	return notify_fail("�����Ǿ���ȵĽ��أ�û��ׯ����������ɵ��Ӳ��ܽ��룡��\n");
        return ::valid_leave(me, dir); 
}
