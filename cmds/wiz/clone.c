
inherit F_DBASE;
#include <ansi.h>
void create() 
{
        seteuid(getuid());
        set("channel_id", "���ƾ���(clone)");
}

int main(object me, string arg)
{
   object obj;
   string err,msg,str,file;
   string filegold,filesilver,filecoin;
string wiz_status;
     int times;
    filegold="/clone/money/gold.c";
    filesilver="/clone/money/silver.c";
    filecoin="/clone/money/coin.c";

    if ( !arg )
        return notify_fail("ָ���ʽ: clone <����> <����> \n");
    if (sscanf(arg, "%s %d", file, times) != 2)
    {
        file = arg;
        times = 1;
    }
        seteuid( geteuid(me) );
        if (!file) file = me->query("cwf");
        if (!file)
                return notify_fail("��Ҫ����ʲ�������\n");

        file = resolve_path(me->query("cwd"), file);
        if( sscanf(file, "%*s.c") != 1 ) file += ".c";
        me->set("cwf", file);

        if( file_size(file) < 0 )
                return notify_fail("û���������(" + file + ")��\n");

        if( !find_object(file) ) {
                err = catch(call_other(file, "???"));
                if (err) {
                        write("����ʧ�ܣ�" + err + "\n");
                        return 1;
                }
        }

        err = catch(obj = new(file));
        if (err) {
                write("����ʧ�ܣ�" + err + "\n");
                return 1;
        }
        
         if ((!(file==filegold) && !(file==filesilver) &&
                 !(file==filecoin)) && (times>10))
        {
                return notify_fail("STOP��STOP�����ֻ�ܸ���10����λ��\n");
        }
        else
                if (times>100)
                {
                return notify_fail("�����ǲ������ϣ���Ǯ���ֻ�ܸ���100����λ!\n");
                }          

if (obj->query("no_clone") && wiz_level(me)<wiz_level("(arch)"))        
                {
                return notify_fail("����������ܱ�����!\n");
                }          

        if( !stringp(msg = me->query("env/msg_clone")) )
                msg = "ֻ��$N�������һָ�������$n��\n";
        str = me->query("name") + "(" + me->query("id") + ")������" + 
                times + "��" + obj->query("name")
                + "(" + obj->query("id") + ")    " + ctime(time())+ "  ��\n";
        write_file("/log/cmds/clone", str);  
	wiz_status = SECURITY_D->get_status(me);
	if( wiz_status != "(admin)" && wiz_status != "(arch)"
	&& userp(me))
message("channel:chat", HIC"����Ҽල��"+me->name() + "������" + 
                  times + "��"+obj->query("name")+HIC"!"NOR"��\n", users());

        CHANNEL_D->do_channel(this_object(),"sys",me->query("name")+
                "("+me->query("id")+")������" + 
                  times + "��" + obj->query("name")
                  + "(" + base_name(obj) + ")  ��\n");


  if (!obj->is_character()){
   for (int i = times;i>0;i--) {
         obj = new(file);
         obj->move(me);
    }
                write(times + "��" +obj->query("name") + "���Ƴɹ������������Ʒ����\n");
        message_vision(msg + "\n", me, obj);
                return 1;
        }
   for(int j = times; j>0; j--) {
          obj=new(file);
          obj->move(environment(me));
   }
                write(times + "��" + obj->query("name") + "���Ƴɹ�������������䡣\n");
        message_vision(msg + "\n", me, obj);
                return 1;

        destruct(obj);
        return notify_fail("�޷����Ʋ����ƶ������(" + file + ")��\n");
}
