 inherit ROOM;
#include <ansi.h> 
void create()
{
        set("short", HIC"ʥĸ��ɽ��"NOR); 
        set("long", @LONG
����ʥĸ���£���Ŀ������������������ٲ����������������һ���澰����
���ı��㣬�����ܵ����ĵ����⣬���в����ڻ�����ɽ����ѩ����һƬһƬ��ƮƮ
���£��ͺ���ˮ��ĩһ�㣬����̫����������ɢ�䣬�������㶼���ǳ��ɫ��͸
���壬�˵���������״���������ݡ�
LONG); 
        set("type","street");
        set("exits",([
                "up":__DIR__"maze1",
                "northeast":__DIR__"birdroad3",
        ]) );
        set("outdoors", "guanwai");
        set("coor/x",-1260);
        set("coor/y",-90);
        set("coor/z",0); 
        setup();
        replace_program(ROOM);
}     
