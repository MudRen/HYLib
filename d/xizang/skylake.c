 inherit ROOM;
#include <ansi.h> 
void create()
{
        set("short", HIB"���"NOR); 
        set("long", @LONG
ת��һ��ɽ�֣�Ⱥ�廷��֮�У���Ȼ�ǰ�ãã��һƬ��ˮ��ԭ������������
������ĵ�һ�ߺ��������������ڸ��ﺣ����������ˮ�峺���̲�������������Ƭ
Ƭ����ĸ���������ˮ���죬����ˮ����������������ϡ��ذ���Ϊ����ľ��,
�⼴����������̲������ӻ�������      
LONG); 
        set("type","street");
        set("exits",([
                "southup":__DIR__"shanyao",
        ]) );
        set("outdoors", "guanwai");
        set("coor/x",-1280);
        set("coor/y",-100);
        set("coor/z",100); 
        set("resource/water",1);
     set("liquid",([
            "name":"��ˮ",
            "container":"�ڸ��ﺣ"])); 
        setup();
} 
int valid_leave(object me, string dir)
{
        if( userp(me) && dir == "southup" )
        {
        if( me->query("str") < 28 )
            return notify_fail("̧ͷԶ����ʥĸѩ��ֱ��������ѩ���죬���ѩ����֪�δ����Ǿ�ͷ��\n������һ㤣��ո�����ȥ�ĽŲ��Խ������˻���������\n");
                else
                {
                 message_vision(HIR "\n\n$N������Ѫ���ڣ�׳�����ң����쳤Хһ��������������֮��������\n\n"NOR,me);
                         return 1;
                }
        }
        return 1;
}  
