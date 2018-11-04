// cp.c
 
inherit F_CLEAN_UP;
 
int main(object me, string arg)
{
	string src, dst, *dirs;
 
	seteuid(geteuid(me));
	if (!arg || sscanf(arg, "%s %s", src, dst)!=2 ) return
		notify_fail("ָ���ʽ: cp <ԭ����> <Ŀ�굵��> \n");

	src = resolve_path(me->query("cwd"), src);
	dst = resolve_path(me->query("cwd"), dst);

	if( file_size(dst)==-2 ) {
		dirs = explode(src, "/");
		dst += "/" + dirs[sizeof(dirs)-1];
	}
 
       //��������¼��/log/cmds/cp   ����(lywin)
	log_file("cmds/cp",
	sprintf("%s(%s) cpһ��(%s) �� (%s) on %s\n",
	me->name(),  //��¼ʹ�����������
	geteuid(me), //��¼ʹ�������ID
	src,   //��¼Դ�ļ�
	dst,  //��¼Ŀ���ļ�
	ctime(time()) ) ); //��¼ʹ�������ʱ��


	if( cp(src, dst) )
		write("Ok.\n");
	else
		write("��û���㹻�Ķ�дȨ����\n");
	return 1;
}
 
int help(object me)
{
  write(@HELP
ָ���ʽ : cp <ԭ����> <Ŀ�굵��>
 
��ָ�������(��)����������
HELP
    );
    return 1;
}
 
